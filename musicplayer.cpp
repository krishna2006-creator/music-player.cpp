#include<iostream>
#include<string>
using namespace std;
struct song{
string name;
song*prev;
song*next;
};
void selectsong();
song*current=NULL;
song *head=NULL;
song *tail=NULL;
void deletesong();
song *createnode(string name);
void nextsong();
void previoussong();
void addsong();
void display();
int main(){
cout<<"********************"<<endl;
int choice;
do{
cout<<"enter the choice "<<endl;
cout<<"1.Add Song\n2.Show Playlist\n3.selectsong\n4.Next Song\n5.Previous Song\n6.Delete Song\n"<<endl;
cin>>choice;
if(choice==1){
addsong();
}
else if(choice==2){
	display();
}
else if(choice==3){
selectsong();
}
else if(choice==4){
nextsong();
}
else if(choice==5){
previoussong();
}
else if(choice==6){
	deletesong();
}
else if(choice==7){
cout<<"exit..............."<<endl;	
}
}while(choice!=7);
return 0;
}
song *createnode(string name){
song *newnode=new song;
newnode->name=name;
newnode->prev=NULL;
newnode->next=NULL;
return newnode;
}
void addsong(){
string name;
cout<<"enter how many songs do want to add"<<endl;
int no;
cin>>no;
cin.ignore();
for(int i=0;i<no;i++){
cout<<i+1<<":"<<"song add to playlist"<<endl;
getline(cin,name);
song*newnode=createnode(name);
if(head==NULL){
head=newnode;
tail=newnode;
}
else{
tail->next=newnode;
newnode->prev=tail;
tail=newnode;
}
}
}
void display(){
 song *temp=head;
 int i=0;
 while(temp!=NULL){
	 cout<<i+1<<":"<<temp->name<<endl;
           temp=temp->next;
	   i++;
 }
}
void nextsong(){
	cout<<"the next song is playing"<<endl;
if(current!=NULL&&current->next!=NULL){
	current=current->next;
	cout<<"the next song is"<<endl;
	cout<<current->name<<endl;
}
else{
	cout<<"no next songs here choose previous or exit"<<endl;
}
}
void selectsong(){
	display();
current=head;
int choice;
cout<<"enter the number to listen songs"<<endl;
cin>>choice;
int j=1;
if(current!=NULL){
while(current!=NULL){
if(choice==j){
     cout<<"the selected song is"<<endl;
     cout<<j<<":"<<current->name<<endl;
     break;
}
current=current->next;
j++;
}
}
else{
	cout<<"no songs here add or upload songs first"<<endl;
}
}
void previoussong(){
	cout<<"previous song"<<endl;
	if(current==NULL){
		cout<<"select song first"<<endl;
	}
	else if(current!=NULL&&current->prev!=NULL){
	song*prev=current->prev;
	current=prev;
	cout<<"the previous song is"<<endl;
	cout<<prev->name<<endl;
}
else{
	cout<<"no songs here"<<endl;
}
}
void deletesong(){
song *temp=head;
int i=0;
while(temp!=NULL){
cout<<i+1<<":"<<temp->name<<endl;
temp=temp->next;
i++;
}
temp=head;
if(temp!=NULL){
int choice=0;
cout<<"enter the number to delete"<<endl;
cin>>choice;
int j=1;
while(temp!=NULL){
	if(head==tail&&choice==1){
		cout<<"deleting the song"<<endl;
		cout<<1<<":"<<temp->name<<endl;
		delete head;
		tail=NULL;
		head=NULL;
		break;
	}
else if(head==temp&&choice==1){
	cout<<"deleting the song"<<endl;
	cout<<1<<":"<<temp->name<<endl;
	head=head->next;
	head->prev=NULL;// A<->B<->C acutal if we want to delete the first we have to change the head to next node 
         delete temp;
	 break;
}
else if(tail==temp&&choice==i){
	cout<<"deleting the song"<<endl;
	cout<<i<<":"<<temp->name<<endl;
	tail=tail->prev;
	tail->next=NULL;
	delete temp;
	break;
}
else if(choice==j){
	cout<<"deleting the song"<<endl;
	cout<<j<<":"<<temp->name<<endl;
temp->prev->next=temp->next;//a-b-c-d remove c; we have join the previous node to next node 
temp->next->prev=temp->prev;
delete temp;
break;
}
temp=temp->next;
j++;}
}
else{
cout<<"no songs here"<<endl;
}
}

