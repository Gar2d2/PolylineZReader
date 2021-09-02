# PolylineZReader 
## Simple app to read Polyline and PolylineZ from ESRI shapefile

MFC dll required to use
Vs config 
c/c++ -> additional include dir $(SolutionDir)/Dependencies/shapelib/Headers
linker -> general -> additional Library dir $(SolutionDir)/Dependencies/shapelib/Library
linker -> input -> additional dependencies shapelib.lib;shapelib_i.lib;

![image](https://user-images.githubusercontent.com/56792313/131875781-03647627-283b-47db-9609-d0845a7f8dff.png)
![image](https://user-images.githubusercontent.com/56792313/131875965-1dd64590-e300-40c3-86e4-14c344cc9f04.png)
