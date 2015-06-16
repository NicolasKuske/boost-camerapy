#include <string> 
#include <cameralibrary.h>


 using std::string;
 using namespace CameraLibrary;


class Some {
	

	public:
	    static const int NOT_AN_IDENTIFIER = -1;

	    Some();
	    Some(int some_id, string const& name);	

		int ID() const;
	    string const& Name() const;
	  
		void ResetID();
	    void ResetID(int some_id);
	
	    void SomeChanges(int some_id, string const& name);
	

	     // public camera API 
	     void initialize();
		 bool acinitialize();
		 Camera& GetCamera();
			

	private:
			int mID;
			string mName;
					

						
};
