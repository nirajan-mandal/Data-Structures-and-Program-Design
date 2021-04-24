#ifndef H_VideoLinkedListType
#define H_VideoLinkedListType

#include <iostream>
#include <string>
#include "linkedList.h"
#include "videoType.h"

using namespace std;

class videoListType: public linkedListType<videoType> 
{ 
public:     
	bool videoSearch(string vTitle);
		//Function to search the list to see whether a
		//particular title, specified by the parameter title,
		//is in the store.
		//Postcondition: Returns true if the title is found; 
		//               otherwise, returns false.

    bool isVideoAvailable(string vTitle);
		//Function to return true if at least one copy of a 
		//particular video is in the store.     

	void videoCheckOut(string title);
		//Function to check out a video, that is, rent a video.
		//Postcondition: copiesInStock is decremented by one.

    void videoCheckIn(string vTitle);
		//Function to check in a video returned by a customer.
		//Postcondition: copiesInstock is incremented by one.     

	bool videoCheckTitle(string vTitle);
		//Function to determine whether a particular video is in 
		//the store.
		//Postcondition: Returns true if the video title is the
		//               same as vTitle; otherwise, returns 
		//               false.

    void videoUpdateInStock(string vTitle, int num);
		//Function to update the number of copies of a video
		//by adding the value of the parameter num. The 
		//parameter vTitle specifies the name of the video for
		//which the number of copies is to be updated.
		//Postcondition: copiesInStock = copiesInStock + num   

	void videoSetCopiesInStock(string vTitle, int num);
		//Function to reset the number of copies of a video.
		//The parameter vTitle specifies the name of the video
		//for which the number of copies is to be reset; the 
		//parameter num specifies the number of copies.
		//Postcondition: copiesInStock = num     

	void videoPrintTitle();
		//Function to print the titles of all the videos in the store.

 private:     
	 void searchVideoList(string vTitle, bool& found,
				          nodeType<videoType>* &current);
		//Function to searche the video list for a particular
		//video, specified by the parameter vTitle. 
		//Postcondition: If the video is found, the parameter 
		//               found is set to true; otherwise, it is set 
		//               to false. The parameter current points to 
		//               the node containing the video.
};
#endif



