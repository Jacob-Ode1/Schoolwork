#include <iostream>
#include <string>
using namespace std;

string handle(string id){
	
	for(int c=0;c<id.length();c++){
		if(id[c]=='.'){
			string q = id.substr(c,(id.length()-c));
			if(q==".net"||q==".com"||q==".info"||q==".org"){
				return q;}
			break;}
		}
	return "";}
			

int main(){
	string in="";
	string core="";
	while (in!="q"){
		cout<<"Enter the next domain name (or type q to exit) :\n";
		cin>>in;
		core=handle(in);
		if(core!=""){
			cout<<"\""<<in<<"\""<<"is a second-level-domain followed by a core gTLD of \""<<core<<"\"\n";}
		else{
			cout<<"\""<<in<<"\""<<"is not a second-level-domain followed by a core gTLD\n";}
		
	}	
}

