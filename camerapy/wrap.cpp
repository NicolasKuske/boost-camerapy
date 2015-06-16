#include <boost/python.hpp> 
 #include <string>
 #include "some.h"
 #include <cameralibrary.h>


 using namespace CameraLibrary;
 using namespace boost::python;


 // getters 


 Camera& GetCamera(Some& obj)
 {
	     return obj.GetCamera();
 }




 BOOST_PYTHON_MODULE(camerapy)
 {
     // wrapping camera class
     class_<Camera>("Camera")
.def("Exposure", &Camera::Exposure)
;


     // wrapping CameraManager with "Some" test class 
     class_<Some>("Some")


         // camera manager API 
.def("initialize", &Some::initialize) //is probably just waits a certain defined amount of time (some constant maximum delay of initialization, approximated before)
                                      
//bool     AreCamerasInitialized();   //== Check and see if all attached cameras are init'd --- probably pings to every camera and waits for return signal
.def("acinitialize", &Some::acinitialize )

.def("GetCamera", GetCamera, return_value_policy<reference_existing_object>())


         // some playground 
.def(init<int, string>(args("some_id", "name")))
.def("ID", &Some::ID)
.def("Name", &Some::Name, return_value_policy<copy_const_reference>())
.def("ResetID", static_cast<void (Some::*)()>(&Some::ResetID))
.def("ResetID", static_cast<void (Some::*)(int)>(&Some::ResetID), args("some_id"))
.def("SomeChanges", &Some::SomeChanges, args("some_id", "name"))
.add_static_property("NOT_AN_IDENTIFIER", make_getter(&Some::NOT_AN_IDENTIFIER))
;
}
