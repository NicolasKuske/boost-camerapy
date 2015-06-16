
#include "some.h" 
 #include <cameralibrary.h>


 using namespace CameraLibrary;

 Some::Some()
     : mID(NOT_AN_IDENTIFIER)
 {
 }

 Some::Some(int some_id, string const& name)
     : mID(some_id), mName(name)
{
}


 int Some::ID() const
 {
     return mID;
 }


 string const& Some::Name() const
 {
     return mName;
 }


 void Some::ResetID()
 {
     mID = NOT_AN_IDENTIFIER;
 }


 void Some::ResetID(int some_id)
 {
     mID = some_id;
 }


 void Some::SomeChanges(int some_id, string const& name)
 {
     mID = some_id;
     mName = name;
 }


 // public camera API 


 void Some::initialize()
 {
     printf("WaitForInitialization is called on the C++ level...\n");


     CameraManager::X().WaitForInitialization();
 }

 bool Some::acinitialize()
 {
	 printf("AreAllCamerasInitialized is called on the C++ level...\n");


	 return CameraManager::X().AreCamerasInitialized();
 }


 Camera& Some::GetCamera()
{
	     printf("Getting camera is called on the C++ level...\n");
	

	     Camera* foo = CameraManager::X().GetCamera();
	     return (Camera&)foo;
	}