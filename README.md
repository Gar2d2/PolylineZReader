# PolylineZReader - simple app to read Polyline and PolylineZ from ESRI shapefile
MFC dll required to use

Vs config 
c/c++ -> additional include dir $(SolutionDir)/Dependencies/shapelib/Headers
linker -> general -> additional Library dir $(SolutionDir)/Dependencies/shapelib/Library
linker -> input -> additional dependencies shapelib.lib;shapelib_i.lib;
