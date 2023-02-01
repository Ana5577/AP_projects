#include <iostream>
#include <string>
#include<vector>
using namespace std;
#include<fstream>
#include <stdio.h>

string readnthline(string fileadd, int n)
{
   fstream file;
   file.open(fileadd,ios::in);

   string s;   
   for(int i = 0; i < n-1; i++)
       getline(file, s);

   getline(file,s);
   return s; 
}



class User{
    public:
    void setusername(string username){UserName=username;}
    string getusername(){return UserName;}
    void setpassword(string password){ Password=password;}
    string getpassword(){return Password;}
    void setfirstname(string firstname){ FirstName=firstname;}
    string getfirstname(){return  FirstName;}
    void setlastname(string lastname){LastName=lastname;}
    string getlastname(){return  LastName;}
    void setbirthdate(string birthdate){BirthDate=birthdate;}
    string getbirthdate(){return  BirthDate;}


    User(string username, string password ,string firstname, string lastname, string birthdate){
        UserName=username;
        Password=password;
        FirstName=firstname;
        LastName= lastname;
        BirthDate=birthdate;
    }

    User()
	{
		UserName= "N/A" ;
		Password= "N/A";
		FirstName= "N/A";
		LastName= "N/A";
		BirthDate= "N/A";
	};
    bool login(){
    cout<<"enter your username: "<<endl;
    cin>>UserName;
    cout<<"enter your password: "<<endl;
    cin>>Password;
    fstream userf;
    userf.open("usersfile.txt",ios::in);
    string a;
    string b;
    int i=-1;
    int trueornot;
    while(getline(userf,a)){
         i++;
        if(i%5==0){
            if (UserName==a){
                if(readnthline("usersfile.txt",i+2)==Password){
                  trueornot=1;
                    break;
                }
                else{
                    cout<<"Wrong password";
                    trueornot=0;
                    userf.close();
                    return false;
                }
                }
                
            }
            else{
                continue;
            
            }
       
    }    

    userf.close();
    if(trueornot==1){
        return true ;
    }
    else{
        cout<<"Username not found";
        return false;
    }
        
        
    };
    
    void reg(){
        cout<<"enter your username: "<<endl;
        cin>>UserName;
        
   
    fstream file;
    file.open("usersfile.txt",ios::in);
    string a;
    int found=0;
    int i=-1;
    while(getline(file,a)){
         i++;
        if(i%5==0){
            if (UserName==a){
                found=1;
                    break;
            }
    
        }
                
        else{
            continue;
            }
       
    }    


    file.close();

    if (found==0){
         cout<<"enter your password: "<<endl;
        cin>>Password;
        cout<<"enter your firstname: "<<endl;
        cin>>FirstName; 
        cout<<"enter your lastname: "<<endl;
        cin>>LastName;
        cout<<"enter your birthdate: "<<endl;
        cin>>BirthDate;

		fstream file1;
        file1.open("usersfile.txt", ios::app);
        file1 <<endl;
		file1 << UserName;
        file1 << endl;
        file1 << Password;
        file1 << endl;
        file1 << FirstName;
        file1 << endl;
        file1 << LastName;
        file1 << endl;
        file1<< BirthDate;
		cout << "User Added Successfully" << endl;

		file1.close();
	}

    if(found==1){
        cout<<"Username exists try another username."<<endl;
        reg();
    }

   }


    private:
    string UserName;
    string Password;
    string FirstName;
    string LastName;
    string BirthDate;

   
};











class Book{
   public:

   void settitle(string title){Title=title;}
   string gettitle(){return Title;}
   void setshelfnumber(string shelfnumber){ShelfNumber=shelfnumber;}
   string getshelfnumber(){return ShelfNumber;}
   void setauthor(string author){Author=author; }
   string getauthor(){return Author;}
   void setedition(string edition){Edition=edition;}
    string getedition(){return Edition;}
    void setpublisher(string publisher){Publisher=publisher;}
    string getpublisher(){return Publisher;}
    void setpublishedyear(int publishedyear){Publishedyear=publishedyear;}
    int getpublishedyear(){ return Publishedyear;}
    void setisbn(long isbn){ISBN=isbn; }
    long getisbn(){return ISBN;}
    void setlength(long length){Length=length;}
    int getlength(){ return Length;}
    void setsubjects(string subjects){ Subjects=subjects;}
    string getsubjects(){return Subjects;}
    void setstatus(int status){ Status=status;}
    int getstatus(){return Status;}
    void setbookuser(string bookuser){ Bookuser=bookuser;}
    string getbookuser(){return Bookuser;}

   Book(string title, string  shelfnumber, string author,string edition,string publisher,int publishedyear,long isbn,long length,string subjects)
    {
    Title=title;
    ShelfNumber=shelfnumber;
    Author=author;
    Edition=edition;
    Publisher=publisher;
    Publishedyear=publishedyear;
    ISBN=isbn;
    Length=length;
    Subjects=subjects;
    Status=0;
    Bookuser="N/A";

   }
   Book(){
    Title="N/A";
    ShelfNumber="N/A";
    Author="N/A";
    Edition="N/A";
    Publisher="N/A";
    Publishedyear=-1;
    ISBN=0;
    Length=0;
    Subjects="N/A";
    Status=0;
    Bookuser="N/A";
   }


    private:
    string Title; //0
    string  ShelfNumber; //1
    string Author; //2
    string Edition; //3
    string Publisher; //4
    int Publishedyear; //5
    long ISBN; //6
    int Length; //7
    string Subjects; //8
    int Status; //9
    string Bookuser; //10



};





Book searchbook(){
    string title1;
    string author1;
    string publisher1;
    int publishedyear1=-1;
    string publishedyear2;
    cout<<"Enter N/A if you want to leave a field empty."<<endl;
    cout<<"Enter title:";
    cin.ignore();
    getline(cin,title1);
    cout<<"Enter author:";
    getline(cin,author1);
    cout<<"Enter publisher:";
    getline(cin,publisher1);
    cout<<"Enter publishedyear:";
    getline(cin,publishedyear2);

     
    vector<Book> v;
    v.clear();
    string ti=title1; //0
    string au=author1; //2
    string pr=publisher1; //4
    if(publishedyear2!="N/A"){
        publishedyear1=stoi(publishedyear2);
    }
    int py=publishedyear1; //5
   
    string a;
    int count1=0;
    int i=0;
    Book book;
    int count=0;
    fstream file;
    file.open("booksfile.txt",ios::in);

    while(getline(file,a)){
        
        if(i%11==0){
            book.settitle(a);
            }
        if(i%11==1){
            book.setshelfnumber(a);
        }
        if(i%11==2){
            book.setauthor(a);
           
        }
        if(i%11==3){
            book.setedition(a);
        }

        if(i%11==4){
            book.setpublisher(a);
        }

        if(i%11==5){
            book.setpublishedyear(stoi(a));
            
        }

        if(i%11==6){
            book.setisbn(stol(a));
        }

        if(i%11==7){
            book.setlength(stoi(a));
        }
            

        if(i%11==8){
            book.setsubjects(a);
        }

        if(i%11==9){
            book.setstatus(stoi(a));
        }

        if(i%11==10){
            book.setbookuser(a);
            v.push_back(book);
            count++;
        }
      i++;  
        
    }    
    file.close();

    
    int flag=0;
    for(int i=0;i<v.size();i++){
        if(v[i].gettitle()==ti & au=="N/A"&pr=="N/A"& py==-1){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW: "<<i<<endl;
        }
        if(ti=="N/A"&v[i].getauthor()==au & pr=="N/A"&  py==-1){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW: "<<i<<endl;
        }
        
        if(ti=="N/A" & au=="N/A" &  v[i].getpublisher()==pr&  py==-1){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW: "<<i<<endl;
        }
        if(ti=="N/A" &au=="N/A" &  pr=="N/A"&  v[i].getpublishedyear()==py){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW: "<<i<<endl;
        }

        if(v[i].gettitle()==ti &  v[i].getauthor()==au &  pr=="N/A"& py==-1){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW:"<<i<<endl;
        }

        if(v[i].gettitle()==ti& au=="N/A"& v[i].getpublisher()==pr& py==-1){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW:"<<i<<endl;
        }

        if(v[i].gettitle()==ti& au=="N/A"& pr=="N/A"& v[i].getpublishedyear()==py){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW:"<<i<<endl;
        }
        
        if(ti=="N/A"& v[i].getauthor()==au & v[i].getpublisher()==pr& py==-1){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW:"<<i<<endl;
        }

        if(ti=="N/A" & v[i].getauthor()==au & pr=="N/A" &v[i].getpublishedyear()==py){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW:"<<i<<endl;
        }

        if(ti=="N/A" & au=="N/A" & v[i].getpublisher()==pr& v[i].getpublishedyear()==py){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW:"<<i<<endl;
        }
        if(v[i].gettitle()==ti & v[i].getauthor()==au & v[i].getpublisher()==pr& py==-1){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW:"<<i<<endl;
        }
        if(v[i].gettitle()==ti & v[i].getauthor()==au &pr=="N/A"& v[i].getpublishedyear()==py){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW:"<<i<<endl;
        }

        if(v[i].gettitle()==ti & au=="N/A" & v[i].getpublisher()==pr& v[i].getpublishedyear()==py){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW:"<<i<<endl;
        }

        if(ti=="N/A" &v[i].getauthor()==au & v[i].getpublisher()==pr& v[i].getpublishedyear()==py){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW:"<<i<<endl;
        }

        if(v[i].gettitle()==ti &v[i].getauthor()==au & v[i].getpublisher()==pr& v[i].getpublishedyear()==py){
            flag=1;
            cout<<v[i].gettitle()<<" "<<v[i].getauthor()<<" "<<v[i].getpublisher()<<" "<<v[i].getpublishedyear()<<" "<<"ROW:"<<i<<endl;
        }

        

    }
    Book book2;
    if(flag==0){
        cout<<endl<<"No matching results."<<endl;
        return book2;
    }
    else{
    int r;
    cout<<endl<<"Enter number of the row which contains the information of the book you want:"<<endl;
    cin>>r;
    return v[r];
    }
}


void borrowbook(User user){
    fstream file;
    file.open("booksfile.txt",ios::in);
    string a;
    int count1=0;
    int i=-1;
    while(getline(file,a)){
        i++;
        if(i%11==10){
            if (user.getusername()==a){
                count1+=1;
            }
    
        }
                
        else{
            continue;
            }
        
    }    
    file.close();


    


    if(count1==2){
        cout<<"You've already borrowed two books";
    }

   
    else{
    Book book;
    book=searchbook();
    
    if (book.getstatus()==1){
        cout<<"This book is already borrowed";
    }
    else{
        book.setstatus(1);
        book.setbookuser(user.getusername());
        cout<<"Book successfully borrowed.";

    //rewrite kardan file
    fstream filee; 
    filee.open("booksfile.txt",ios::in);
    
    fstream temp;
    temp.open("temp.txt",ios::out);
    string line;
    int i=-1;
    while (getline(filee, line)){
        i++;
    if (i%11==6){ 
        // isbn is unique
        if(line != to_string(book.getisbn())){
           for(int j=6;j>-5;j--){
           temp << readnthline("booksfile.txt", i-j+1) << endl;
           }
        }

        if(line==to_string(book.getisbn())){
            temp<<book.gettitle()<<endl;
            temp<<book.getshelfnumber()<<endl;
            temp<<book.getauthor()<<endl;
            temp<<book.getedition()<<endl;
            temp<<book.getpublisher()<<endl;
            temp<<book.getpublishedyear()<<endl;
            temp<<book.getisbn()<<endl;
            temp<<book.getlength()<<endl;
            temp<<book.getsubjects()<<endl;
            temp<<book.getstatus()<<endl;
            temp<<book.getbookuser()<<endl;
        }
    }
    else {
        continue;
    }
    }

    filee.close();
    temp.close();
    remove("booksfile.txt");
    rename("temp.txt", "booksfile.txt");
 
    }
}
};





void returnbook(User user){
    Book book;
    book=searchbook();
    if(book.getbookuser()==user.getusername()){
    book.setstatus(0);
    book.setbookuser("N/A");
    fstream file; 
    file.open("booksfile.txt",ios::in);
    fstream temp;
    temp.open("temp.txt",ios::out);
    string line;
    int i=-1;
    while (getline(file, line)){
        i++;
    if (i%11==6){ 
        // isbn is unique
        if(line != to_string(book.getisbn())){
           for(int j=6;j>-5;j--){
           temp << readnthline("booksfile.txt", i-j+1) << endl;
           }
        }

        if(line==to_string(book.getisbn())){
            temp<<book.gettitle()<<endl;
            temp<<book.getshelfnumber()<<endl;
            temp<<book.getauthor()<<endl;
            temp<<book.getedition()<<endl;
            temp<<book.getpublisher()<<endl;
            temp<<book.getpublishedyear()<<endl;
            temp<<book.getisbn()<<endl;
            temp<<book.getlength()<<endl;
            temp<<book.getsubjects()<<endl;
            temp<<book.getstatus()<<endl;
            temp<<book.getbookuser()<<endl;
        }
    }
    else {
        continue;
    }
    }

    file.close();
    temp.close();
    remove("booksfile.txt");
    rename("temp.txt", "booksfile.txt");
    cout<<"Book successfully returned.";
 
    }

    else{
        cout<<"You didn't borrow this book.";
    }
};










int main(){
    cout<<"if you want to login enter 1, if you want to register enter 2: ";
    int ch1;
    cin>>ch1;
    if(ch1==1){
        User user;
        if(user.login()==true){
            cout<<"if you want to search for a book enter 1, if you want to borrow a book enter 2, if you want to return a book enter 3: ";
            int ch2;
            cin>>ch2;
            if(ch2==1){
                Book book;
                book=searchbook();
                cout<<"Title: "<<book.gettitle()<<" "<<"ShelfNumber: "<<book.getshelfnumber()<<" "<<"Author: "<<book.getauthor()<<" "<<"Edition: "<<book.getedition()<<" "<<"Publisher: "<<book.getpublisher()<<" "<<"Published Year: "<<book.getpublishedyear()<<" "<<"ISBN: "<<book.getisbn()<<" "<<"Length: "<<book.getlength()<<" "<<"Subjects: "<<book.getsubjects()<<" "<<"Status: "<<book.getstatus()<<endl;
            }
            else if(ch2==2)
            {
                borrowbook(user);
            }

            else if(ch2==3){
                returnbook(user);
            }
            else{
                cout<<"Invalid Input";
            }

        
        }
    }
    else if(ch1==2){
        User user;
        user.reg();
        
    }

    else{
        cout<<"Invalid Input";
    }
    return 0;
}
