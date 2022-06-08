import json
import requests
from bs4 import BeautifulSoup


def download_files(file_name, date_range, html_val):
    date_list = date_range.split("-")
    start_date = int(date_list[0])
    end_date = int(date_list[1])
    url_list = []
    URL = "https://apps.irs.gov/app/picklist/list/priorFormPublication.html?resultsPerPage=200&sortColumn=sortOrder" \
          "&indexOfFirstRow=0&criteria=formNumber&value=" + html_val + "&isDescending=false"
    page = requests.get(URL)
    soup = BeautifulSoup(page.content, 'html.parser')
    results = soup.find(id="picklistContentPane")
    job_elems = results.findAll('tr', class_='even')
    for job_elem in job_elems:
        name_elem = str(job_elem.find('td', class_="LeftCellSpacer").text).strip()
        date_elem = int(job_elem.find('td', class_='EndCellSpacer').text)
        if start_date <= date_elem <= end_date:
            hyperlink = job_elem.find('td', class_="LeftCellSpacer")
            link = hyperlink.find('a', href=True)
            print(link['href'])
            r = requests.get(str(link['href']))
            with open(file_name + " " + str(date_elem) + ".pdf", 'wb') as f:
                f.write(r.content)
                f.close()


def analyze(html_val, form_name):
    returnable = {}
    dates = []
    title = ''
    max_year = 0
    min_year = 0
    form_title = form_name
    URL = "https://apps.irs.gov/app/picklist/list/priorFormPublication.html?resultsPerPage=200&sortColumn=sortOrder" \
          "&indexOfFirstRow=0&criteria=formNumber&value=" + html_val + "&isDescending=false"
    page = requests.get(URL)
    soup = BeautifulSoup(page.content, 'html.parser')
    results = soup.find(id="picklistContentPane")

    job_elems = results.findAll('tr', class_='even')
    for job_elem in job_elems:

        name_elem = str(job_elem.find('td', class_="LeftCellSpacer").text).strip()
        date_elem = job_elem.find('td', class_='EndCellSpacer').text
        if name_elem == form_name:
            title = job_elem.find('td', class_="MiddleCellSpacer").text.strip()
            date_elem = int(str(job_elem.find('td', class_='EndCellSpacer').text).strip())
            dates.append(date_elem)
        else:
            continue

    job_elems = results.findAll('tr', class_='odd')
    for job_elem in job_elems:

        name_elem = str(job_elem.find('td', class_="LeftCellSpacer").text).strip()
        date_elem = job_elem.find('td', class_='EndCellSpacer').text
        if name_elem == form_name:
            title = job_elem.find('td', class_="MiddleCellSpacer").text.strip()
            date_elem = int(str(job_elem.find('td', class_='EndCellSpacer').text).strip())
            dates.append(date_elem)
        else:
            continue

    returnable["form_number"] = form_name
    returnable["form_title"] = title
    returnable["min_year"] = min(dates)
    returnable["max_year"] = max(dates)
    return returnable


def make_item():
    returnable = list()
    returnable.append(input("What is the name of the file?\n>"))
    returnable.append(input("What is the file range?\n>"))
    print(returnable)
    return returnable


def make_list():
    user_input = input("Please provide list of forms separated by comma, e.g. Form W-2,Form 1095-C, ...: ")
    a_list = list(map(str, user_input.split(',')))
    return a_list


def get_choice():
    user_choice = ""
    while user_choice != "1" and user_choice != "2":
        print("Welcome! What would you like to do?\n")
        print("1. give a list of tax form names (ex: Form W-2, Form 1095-C), search the website and return some "
              "informational results. NO SPACES BETWEEN FILES ONLY COMMAS\n")
        print(
            "2. Give a tax form name (ex: Form W-2) and a range of years (inclusive, 2018-2020should fetch three "
            "years), "
            "download all PDFs available within that range.\n")
        print("\n\n\n#####please press 1 or 2 for your option#####\n >")
        user_choice = input()
    return user_choice


def main():
    user_choice = int(get_choice())
    if user_choice == 1:
        # form list = [form-name1, form-name2, etc]
        form_list = make_list()
        printable = {}
        form_list = ["Form 1095-C", "Form W-2"]
        for i in range(len(form_list)):
            html_val = form_list[i].replace(" ", "+")
            printable[i] = analyze(html_val, form_list[i])
        json_object = json.dumps(printable, indent=4)
        print(json_object)
        return json_object

    elif user_choice == 2:
        # form list = [file name, date range]
        form_list = make_item()
        html_val = form_list[0].replace(" ", "+")
        download_files(form_list[0], form_list[1], html_val)

main()
