Java Animation Renderer


This was a project that focused heavily on the MVC layout in order to function. The goal of this program is to read in data via
text or SVG and turn that into an animation(Some example animations are included in the output folder). 

The model instance was formed using a singleton
pattern, and then built using a combination of the Builder/Factory patterns. The Reason for this is that the data input could
vary, so having a model built around taking in both data types would break common OOP practice. To make it work, the program
parses everything into string data and transforms them into viable objects. Those objects are then added to a frame, and posted
to the view. 
