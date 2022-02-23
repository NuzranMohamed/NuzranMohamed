#include<iostream>
#include<string>
#include<iomanip>               //using libraries
#include<fstream>
#include<cmath>

using namespace std;

 //making a global variable(testfilename for taking the test file for comparison)
string testfilename;            
int phrasecount=0;

//making a class named radacox
class radacox
{
	public:    //declaring public variables

    float index;                //index variable for index of files
 	float wordcount=0;          //wordcount variable for common words between two files 
    float twcount=0;            // twcount for total word of test file   
	float swcount=0;           //swcount for total words for source file   (in comparison for only one file)

	string word1;            //word1 for the storage of test file words
	string word2;            //word2 for the storage of source file words
	string phrase="";        //phrase for the storage of common phrases
	string sourcefilename;   //sourcefilename for the taking the sourcefile for comparison
	string phaser[1000];     //declaring array for storing the  plenty of phrases 
	int ph=0;                //ph for phrase count 
	int x=0,s=0;             //x and s in purpose of distinction of phrase from words 
	//int phrasecount=0;       //phrasecount for the phrase count 

// making a function for counting of words 
void word_counter()    
	 {
        
		 string tw;    //declaring a string for the increase in tthe wordcount

		 ifstream testfile(testfilename.c_str());    //opening the test file

		                     //mkaing a loop
          while(!testfile.eof()) 
		 {                                           /*this loop increases the wordcount  as the pointers goes across a word in  the test
		                                               file*/
			 testfile>>tw;
			 twcount++;
		 }

		 ifstream sourcefile(sourcefilename.c_str());         //opening the source file
                            //making a loop
		 while(!sourcefile.eof())
		 {
			 sourcefile>>tw;                                  /*this loop increases the wordcount  as the pointers goes across a word in  the test
		                                                file*/
			 swcount++;
		 }
     
          sourcefile.close();                               //closing the sourcefile 
		  testfile.close();                                 //closing the test file
	}
       //makinga function for counting the similarity index btw 2 files
void	similarity_word()
{
	
	index=(wordcount/(swcount+twcount))*100;            //implementing the formula
    
}
	


            //making a function for the input of testfile
 	radacox() {
		ifstream testfile(testfilename.c_str());    //opening the test file
		
		
		cout<<"Enter source file(with extention '.txt')=";    //program demanding the test file
		cin>>sourcefilename;                                  //for the input of test file


		ifstream sourcefile(sourcefilename.c_str());    //opening of source file                     
		
		                               
		                                           
		while(!testfile.eof())                            /*making a loop with if for purpose of increasing in word count and phrase count 
		                                                   and to also store the phrases in phaser*/
		{                                    
			testfile>>word1;
			sourcefile.clear();                      //to clear the previous working(matching of words)
			sourcefile.seekg(0,ios::beg);            //as we use end of file , this function id for the ponter to again move to the head start
			while(!sourcefile.eof()){
				sourcefile>>word2;
				
				if(word1==word2)
			{
					phrase=phrase + " " + word1;
				    wordcount++;                        //the condition for incrreasing the word count is in this if statement 
					                                    
					x++;                                //as the two words together match the valu of x increases by 1 everytime 
			  
					s=1;                                //when the two words together dont match the s will be 1
					
					break;
		}
		s=0;                           /*when th two words together match the the value of s becomes 
		                                  for further processing */

			}
			if(x>=2){phrasecount++;              /*now as the valu of x becomes two or greater 
			                                       the the value of s becomes 0 */
				if (s==0){
				phaser[ph]=phrase;                   //phrase will store in the array named phaser 
				phrase="";
				x=0;                                     //the value of x will re initialize every time to 0
				ph++;}                                //phrasecount increases 
				
				}
			
		}
		
		

	    testfile.close();
		                             //closing the files
		sourcefile.close();
		
	   word_counter();          
	                                                   //calling the functions 
	   similarity_word();       

	};
	
	

};

                     //starting the main function
main(){
	cout<<"please enter the test file(with extention '.txt')=";                 // opening the test file 
		cin>>testfilename;
	radacox a,b,c,d,e;                                                          //while using object orientation programming calling the function 5 times 
	float totalw,tcommonw,tsim;
	totalw=a.swcount+b.swcount+c.swcount+d.swcount+e.swcount+a.twcount;       //adding total word for all files  
    tcommonw=a.wordcount+b.wordcount+c.wordcount+d.wordcount+e.wordcount;     // adding total common words for all file 

	tsim=(tcommonw/totalw)*100;                         //applying the formula for total 5 file   indexes 

	
	cout<<endl<<setw(73)<<"total Number of similar words found="<<tcommonw<<endl;
	cout<<setw(50)<<a.wordcount<<" from file 1"<<endl;
	cout<<setw(50)<<b.wordcount<<" from file 2"<<endl;                              //setting the given format on the console for common words
	cout<<setw(50)<<c.wordcount<<" from file 3"<<endl;
	cout<<setw(50)<<d.wordcount<<" from file 4"<<endl;
	cout<<setw(50)<<e.wordcount<<" from file 5"<<endl;
    cout<<endl;
	cout<<endl;

	cout<<setw(30)<<"Similarity Index="<<tsim<<" %"<<endl;
	cout<<"Source 1\t="<<a.index<<"%\n";
	cout<<"Source 2\t="<<b.index<<"%\n";
	cout<<"Source 3\t="<<c.index<<"%\n";                                   //setting the given format on the console for similarity indexes 
	cout<<"Source 4\t="<<d.index<<"%\n";
	cout<<"Source 5\t="<<e.index<<"%\n";
    
	ofstream testfile(testfilename.c_str(),ios::app);               //opening the file 
	testfile<<endl<<endl<<setw(30)<<"Similarity Index="<<tsim<<" %"<<endl;
	testfile<<"Source 1\t="<<a.index<<"%\n";
	testfile<<"Source 2\t="<<b.index<<"%\n";
	testfile<<"Source 3\t="<<c.index<<"%\n";                               //setting the given format on the testfile for similarity indexes 
	testfile<<"Source 4\t="<<d.index<<"%\n";
	testfile<<"Source 5\t="<<e.index<<"%\n";
	
	//showing the phrases on the console
	
	cout<<endl<<endl;
	
	cout<<"number of similar phrases/clauses"<<setw(30)<<phrasecount;
	cout<<endl;

	cout<<"similar phrases/clauses"<<setw(30)<<"sourcefile"<<endl;
	cout<<",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,";
	
    cout<<endl<<endl;
	for(int i=0;i<a.ph;i++)
	{
		cout<<a.phaser[i]<<setw(30)<<"1"<<endl;
	}

	cout<<endl<<endl;
	for(int i=0;i<b.ph;i++)
	{
		cout<<left<<b.phaser[i]<<setw(30)<<right<<"2"<<endl;
	}

	cout<<endl<<endl;
	for(int i=0;i<c.ph;i++)                                                //setting the for loops for the printing of phrases on the test file 
	{
		cout<<c.phaser[i]<<setw(30)<<right<<"3"<<endl;
	}

	cout<<endl<<endl;
	for(int i=0;i<d.ph;i++)
	{
		cout<<d.phaser[i]<<setw(30)<<"4"<<endl;
	}

	cout<<endl<<endl;
	for(int i=0;i<e.ph;i++)
	{
		cout<<e.phaser[i]<<setw(30)<<"5"<<endl;
	}

	 
	 //showing in the file
	
	testfile<<endl<<endl;
	
	testfile<<"number of similar phrases/clauses"<<setw(20)<<phrasecount;
	testfile<<endl;

	testfile<<"similar phrases/clauses"<<setw(30)<<"sourcefile"<<endl;
	testfile<<",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,";
	
    testfile<<endl<<endl;
	for(int i=0;i<a.ph;i++)
	{
		testfile<<a.phaser[i]<<setw(30)<<"1"<<endl;
	}

	testfile<<endl<<endl;
	for(int i=0;i<b.ph;i++)
	{
		testfile<<b.phaser[i]<<setw(30)<<"2"<<endl;
	}

	testfile<<endl<<endl;
	for(int i=0;i<c.ph;i++)                                                //setting the for loops for the printing of phrases on the test file 
	{
		testfile<<c.phaser[i]<<setw(30)<<"3"<<endl;
	}

	testfile<<endl<<endl;
	for(int i=0;i<d.ph;i++)
	{
		testfile<<d.phaser[i]<<setw(30)<<"4"<<endl;
	}

	testfile<<endl<<endl;
	for(int i=0;i<e.ph;i++)
	{
		testfile<<e.phaser[i]<<setw(30)<<"5"<<endl;
	}

	testfile.close();           //closing the test file
}
