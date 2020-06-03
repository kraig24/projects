This is a recent Data Analysis Project that I worked on to recognize which season is represented in a picture. Results
seen in my Linkedin post here:

https://www.linkedin.com/feed/update/urn:li:activity:6669324887724716032/

The goal of this project was to learn how to make data more simplistic so that it can more easily be compared. For example,
I couldn't just compare every pixel in one picture to every pixel in another for each image because 

1) it isn't scalable with large amounts of pictures
2) it would take fare too long


So, in order to solve this problem, I used the Principle Component Analysis algorithm and turned each image into smaller
RGB values. By doing this, I was able to associate images that had snow to similar images in factions of a second. 
There are downsides to this approach, including the fact that if you make the data too simplistic, then you are likely to get
false positives. For that reason, I couldn't drop my analysis below 4 dimensions. I also tried other algorithms like KMeans
and clustering, but without having already labeled data for each season, these performed worse than PCA


The main takeaway I had from this project is how to balance simplifying datasets for analysis while still respecting the
integrity of the data itself. 
