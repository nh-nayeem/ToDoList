#include<bits/stdc++.h>
using namespace std;

vector<pair<string,int> > qu;
bool cmp(pair<string,int> a,pair<string,int> b)
{
    return a.second>b.second;
}
void encrypt(string &s, int key)
{
    for(int i=0;i<s.size();i++)
        s[i]=s[i]+key;
}
void Showlist()
{
    if(qu.empty())
    {
        cout<<"\n\n\tYour list is empty.\n";
        return;
    }
    cout<<"\n\tno. priority  ->  to_do \n\n";
    for(int i=0;i<qu.size();i++)
    {
        cout<<"\t "<<i+1<<" \t"<<qu[i].second<<"\t"<<qu[i].first<<endl;
    }
}
void init(string path)
{
    fstream temp;
    path+="to_do_save.dat";
    temp.open(path.c_str(), std::fstream::in);
    string s;
    int t;
    while(temp>>s && temp>>t)
    {
        encrypt(s,-97-26-1);
        qu.push_back(make_pair(s,t));
    }
    temp.close();
}
void end_prog(string path)
{
    fstream temp;
    path+="to_do_save.dat";
    //cout<<"Writing File: "<<path<<endl;

    temp.open(path.c_str(), std::fstream::out);
    if(!temp.is_open()) cout<<"\n\tError ....\n";
    for(int i=0;i<qu.size();i++)
    {
        string s=qu[i].first;
        encrypt(s, 97+26+1);
        temp<<s;
        temp<<" ";
        temp<<qu[i].second;
        temp<<" ";
    }
    temp.close();
}
void help(string path)
{
    fstream temp;
    path+="help.txt";
    temp.open(path.c_str(), std::fstream::in);
    string line;
    while(getline(temp, line))
        cout<<line<<endl;
    temp.close();
}
int main(int argc, char *argv[])
{

    string path(argv[0]);
    path=path.substr(0, path.size()-9);
    //cout<<path<<endl;
    init(path);
    string s;
    cout<<"command: ";
    while(cin>>s)
    {
        system("CLS");
        if(s=="off") break;
        else if(s=="list")
        {
            Showlist();
        }
        else if(s=="new")
        {
            string s;
            int t;
            cout<<"what to do: ";
            cin>>s;
            system("cls");
            cout<<"set a priority: ";
            cin>>t;
            system("cls");
            qu.push_back(make_pair(s,t));
            sort(qu.begin(),qu.end(),cmp);
        }
        else if(s=="del")
        {
            Showlist();
            cout<<endl<<"which one: ";
            int d;
            cin>>d;
            qu.erase(qu.begin()+d-1);
            system("CLS");
            Showlist();
        }
        else if(s=="top")
        {
            if(qu.empty())
            {
                cout<<"\n\n\tYour list is empty.\n";
            }
            else
            {
                cout<<"\n\n  Do it now. Sometimes 'Later' becomes 'Never'  \n\n";
                cout<<"\n\t priority   ->  to_do \n\n";
                cout<<"\t    "<<qu[0].second<<"\t\t"<<qu[0].first<<endl;
            }

        }
        else if(s=="erase")
        {
            qu.clear();
            cout<<"\n\tAll task erased!!";
        }
        else if(s=="update")
        {
            int i,key;
            Showlist();
            cout<<endl<<"which one: ";
            cin>>i;
            system("cls");
            Showlist();
            cout<<endl<<"set an update value for "<<i<<": ";
            cin>>key;
            qu[i-1].second=key;
            sort(qu.begin(),qu.end(),cmp);
            system("cls");
            Showlist();
        }
        else
        {
            system("cls");
            help(path);
        }
        end_prog(path);
        cout<<endl<<endl<<"command: ";
    }

    system("pause");
    return 0;
}
