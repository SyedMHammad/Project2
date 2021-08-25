#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
	
struct TIME
{
	int hours;
	int minutes;
	int day;	
};
void computeTimeDifference(TIME t1, TIME t2,TIME *difference)
{
   	difference->day = t2.day - t1.day;
    difference->minutes = t2.minutes-t1.minutes;
    difference->hours = t2.hours-t1.hours;
    if(difference->day>0||difference->hours>23){
    	cout<<"                           allow"<<endl;
    	
	}
	else{
		cout<<"                           not allow"<<endl;
		cout<<"                           apply fine"<<endl;
	}
    	
}
class nod
{
	public:
		string data;
		nod *next;
		double score;
		nod()
		{
			data="";
			next=NULL;
			score=0;
		}
		nod(string x,double a)
		{
			data=x;
			score=a;
			next=NULL;
		}
		nod(string x,double a,nod *b)
		{
			data=x;
			score=a;
			next=b;
		}
		nod(string x)
		{
			data=x;
			score=0;
			next=NULL;
		}
		nod(string x,nod *d)
		{
			data=x;
			score=0;
			next=d;
		}
};

class linklist
{
	float arrA[4],arrB[4],arrC[4],arrD[4];
	string B;
	public:
		nod *head,*tail;
		linklist()
		{
			head=NULL;
			for(int i=0;i<4;i++)
			{
				arrA[i]=0.0;
				arrB[i]=0.0;
				arrC[i]=0.0;
				arrD[i]=0.0;
			}
		}
		void addtotail(string a)
		{
			if(head==NULL)
			{
				head=new nod(a);
				tail=head;
			}
			else if(head==tail)
			{
				head->next=new nod(a);
				tail=head->next;
			}
			else
			{
				tail->next=new nod(a);
				tail=tail->next;
			}
		}
		void addtotalin(string a,double x)
		{
			if(head==NULL)
			{
				head=new nod(a,x);
				tail=head;
			}
			else if(head==tail)
			{
				head->next=new nod(a,x);
				tail=head->next;
			}
			else
			{
				tail->next=new nod(a,x);
				tail=tail->next;
			}
		}
		nod *ascendingsort()
		{
			for(nod *temp=head;temp!=NULL;temp=temp->next)
			{
				for(nod *temp2=temp->next;temp2!=NULL;temp2=temp2->next)
				{
					if(temp->score>temp2->score)
					{
						nod temp3;
						temp3.data=temp2->data;
						temp3.score=temp2->score;
						temp2->data=temp->data;
						temp2->score=temp->score;
						temp->data=temp3.data;
						temp->score=temp3.score;
					}
				}
			}
			return head;
		}
		nod *descendingsort()
		{
			for(nod *temp=head;temp!=NULL;temp=temp->next)
			{
				for(nod *temp2=temp->next;temp2!=NULL;temp2=temp2->next)
				{
					if(temp->score<temp2->score)
					{
						nod temp3;
						temp3.data=temp2->data;
						temp3.score=temp2->score;
						temp2->data=temp->data;
						temp2->score=temp->score;
						temp->data=temp3.data;
						temp->score=temp3.score;
					}
				}
			}
			return head;
		}
		void display (struct nod *temp)
		{
			ofstream risk;
			risk.open("RiskFactor.csv", ios::trunc);
			risk <<"House Number" <<","<<"Risk Percentage" << endl;
			while (temp!=NULL)
			{
				cout <<"                           "<< temp->data << "\t" << temp->score <<"%";
				
				risk << temp->data << " , " << temp->score << "%" << endl;
				temp=temp->next;
				cout << endl;
			}
			cout<<"\n"<<endl;
			risk.close();
		}
		
};

struct node
{
	string data;
	TIME tim;
	node *lchild,*rchild;	
}*root=NULL;

class bst
{
	public:
		bst()
		{
			root=NULL;
		}
void insert(node *t,string key,TIME tt)
{
			node *r=NULL;
			node *p;
			p=new node;
			p->data=key;
			p->tim=tt;
			p->lchild=p->rchild=NULL;
			if(t==NULL)
				{
					root=p;
					return;
				}
			while(t!=NULL)
			{
				r=t;
				if(key==t->data)
					return;
				else if(key<t->data)
					t=t->lchild;
				else
					t=t->rchild;
			}
			if(p->data<r->data)
				r->lchild=p;
			else
				r->rchild=p;
		}
		node * Search(string key)
{
node *t=root;
	while(t!=NULL)
	{
		if(key==t->data)
		return t;
		else if(key<t->data)
		t=t->lchild;
		else
		t=t->rchild;
	}
return NULL;
}

void inorder(node *temp)
{
		if(temp==NULL)
		{
			return ;
		}
		inorder(temp->lchild);
		cout<<"                           "<<temp->data<<"\t";
		cout<<temp->tim.hours<<":"<<temp->tim.minutes<<"\t day "<<temp->tim.day<<endl;
		inorder(temp->rchild);
	}
};

nod *removefirstnode(nod *head)
{
	 if (head == NULL) 
        return NULL;   
    // Move the head pointer to the next node 
    nod* temp = head; 
    head = head->next; 
    delete temp; 
    return head; 
}

int main()
{	
	char area;
	int hn;
	int opt;
	string nic;
	cout<<"                              A Covid-19 Relief Program\n\n"<<endl;
	cout<<"                           The Following Program Will Be"<<endl;
	cout<<"                Tracking Citizens In The LockDown Due To The Covid-19"<<endl;
	cout<<"                             Calculating The Risk Factor"<<endl;
	cout<<"                       Helping In The Distribution Of Rations"<<endl;
	cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n"<<endl;
	do
	{
		cout<<"                           What Do You Want To Execute?"<<endl;
		cout<<"                           1.Inserting CNIC Number"<<endl;
		cout<<"                           2.Searching CNIC Number"<<endl;
		cout<<"                           3.Search For The Available Areas"<<endl;
		cout<<"                           4.Calculating The Risk Factor"<<endl;
		cout<<"                           5.EXIT\n"<<endl;
		cout<<"                           ";
		cin>>opt;
		cout<<"\n";
		switch(opt)
		{
			case 1 :
				{
//					cout<<"Enter your area(A,B,C,D):";
					cout<<"                           Enter Your Area Of Residence:"<<endl;
					cout<<"                           A-B-C-D"<<endl;
					cout<<"                           ";
					cin>>area;
					cout<<"                           Enter Your House Number:"<<endl;
					cout<<"                           1-2-3-4"<<endl;
					cout<<"                           ";
					cin>>hn;
					switch(area)
					{
						case 'A':	
						switch(hn)
						{
							case 1:
							{
								fstream a1;
								a1.open("A1.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
	                                pass:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "                           Follow Correct Format Please\n";
										count=0;
										goto pass;
										}
									else
									a1<<nic<<"\n";
									a1<<t.hours<<"\n";
									a1<<t.minutes<<"\n";
									a1<<t.day<<"\n";
								}
							}
							a1.close();
							break;
						}
							//open house 1 file and make object of tree and insert data according to it
						case 2:
						{
							fstream a2;
							a2.open("A2.txt",ios::in | ios::out | ios::app);
							{
								if(!a2.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass2:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass2;
										}
									else
									a2<<nic<<"\n";
									a2<<t.hours<<"\n";
									a2<<t.minutes<<"\n";
									a2<<t.day<<"\n";
								}									
							}
							a2.close();
							break;
						}
							//open house 1 file and make object of tree and insert data according to it
						case 3:
						{
							fstream a3;
							a3.open("A3.txt",ios::in | ios::out | ios::app);
							{
								if(!a3.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass3:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass3;
										}
									else
									a3<<nic<<"\n";
									a3<<t.hours<<"\n";
									a3<<t.minutes<<"\n";
									a3<<t.day<<"\n";
								}
							}
							a3.close();
							ofstream risk;
							break;
						}
							//open house 1 file and make object of tree and insert data according to it
						case 4:
						{
							fstream a4;
							a4.open("A4.txt",ios::in | ios::out | ios::app);
							{
								if(!a4.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass4:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass4;
										}
									else
									a4<<nic<<"\n";
									a4<<t.hours<<"\n";
									a4<<t.minutes<<"\n";
									a4<<t.day<<"\n";
								}
							}
							a4.close();
							ofstream risk;
							break;
						}	
							//open house 1 file and make object of tree and insert data according to it
						default:
							cout<<"                           Invalid Input!";
					}
					break;
				case 'B':
					switch(hn){
						case 1:
							{	
								fstream b1;
							b1.open("B1.txt",ios::in | ios::out | ios::app);
							{
								if(!b1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass5:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass5;
										}
									else
									b1<<nic<<"\n";
									b1<<t.hours<<"\n";
									b1<<t.minutes<<"\n";
									b1<<t.day<<"\n";
								}
							}
							b1.close();
							break;
							}
							//open house 1 file and make object of tree and insert data according to it
						case 2:
							{
								fstream b2;
							b2.open("B2.txt",ios::in | ios::out | ios::app);
							{
								if(!b2.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass6:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass6;
										}
									else
									b2<<nic<<"\n";
									b2<<t.hours<<"\n";
									b2<<t.minutes<<"\n";
									b2<<t.day<<"\n";
								}
							}
							b2.close();
							break;
							}
							//open house 1 file and make object of tree and insert data according to it
						case 3:
							{	
								fstream b3;
							b3.open("B3.txt",ios::in | ios::out | ios::app);
							{
								if(!b3.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass7:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass7;
										}
									else
									b3<<nic<<"\n";
									b3<<t.hours<<"\n";
									b3<<t.minutes<<"\n";
									b3<<t.day<<"\n";
								}
							}
							b3.close();
							break;
							}
							//open house 1 file and make object of tree and insert data according to it
						case 4:
							{	
								fstream b4;
							b4.open("B4.txt",ios::in | ios::out | ios::app);
							{
								if(!b4.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass8:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass8;
										}
									else
									b4<<nic<<"\n";
									b4<<t.hours<<"\n";
									b4<<t.minutes<<"\n";
									b4<<t.day<<"\n";
								}
							}
							b4.close();
							break;
							}
							//open house 1 file and make object of tree and insert data according to it
						default:
							cout<<"                           Invalid";
					}
					break;
				case 'C':
					switch(hn){
						case 1:
						{	
							fstream c1;
							c1.open("C1.txt",ios::in | ios::out | ios::app);
							{
								if(!c1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass9:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass9;
										}
									else									
									c1<<nic<<"\n";
									c1<<t.hours<<"\n";
									c1<<t.minutes<<"\n";
									c1<<t.day<<"\n";
								}
							}
							c1.close();
							break;
							}
							//open house 1 file and make object of tree and insert data according to it
						case 2:
						{
							fstream c2;
							c2.open("C2.txt",ios::in | ios::out | ios::app);
							{
								if(!c2.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass10:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass10;
										}
									else									
									c2<<nic<<"\n";
									c2<<t.hours<<"\n";
									c2<<t.minutes<<"\n";
									c2<<t.day<<"\n";
								}
							}
							c2.close();
							break;
							}
							//open house 1 file and make object of tree and insert data according to it
						case 3:
						{	
							fstream c3;
							c3.open("C3.txt",ios::in | ios::out | ios::app);
							{
								if(!c3.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass11:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass11;
										}
									else									
									c3<<nic<<"\n";
									c3<<t.hours<<"\n";
									c3<<t.minutes<<"\n";
									c3<<t.day<<"\n";	
								}
							}
							c3.close();
							break;
							}
							//open house 1 file and make object of tree and insert data according to it
						case 4:
						{	
							fstream c4;
							c4.open("C4.txt",ios::in | ios::out | ios::app);
							{
								if(!c4.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass12:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass12;
										}
									else									
									c4<<nic<<"\n";
									c4<<t.hours<<"\n";
									c4<<t.minutes<<"\n";
									c4<<t.day<<"\n";
								}
							}
							c4.close();
							break;
							}
							
							//open house 1 file and make object of tree and insert data according to it
						default:
							cout<<"                           Invalid!";
					}
					break;
				case 'D':
					switch(hn){
						case 1:
						{	
							fstream d1;
							d1.open("D1.txt",ios::in | ios::out | ios::app);
							{
								if(!d1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass13:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass13;
										}
									else									
									d1<<nic<<"\n";
									d1<<t.hours<<"\n";
									d1<<t.minutes<<"\n";
									d1<<t.day<<"\n";
								}
							}
							d1.close();
							break;
						}
							//open house 1 file and make object of tree and insert data according to it
						case 2:
						{	
							fstream d2;
							d2.open("D2.txt",ios::in | ios::out | ios::app);
							{
								if(!d2.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass14:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass14;
										}
									else									
									d2<<nic<<"\n";
									d2<<t.hours<<"\n";
									d2<<t.minutes<<"\n";
									d2<<t.day<<"\n";
									}
							
							}
							d2.close();
							break;
						}
							
							//open house 1 file and make object of tree and insert data according to it
						case 3:
						{	
							fstream d3;
							d3.open("D3.txt",ios::in | ios::out | ios::app);
							{
								if(!d3.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass15:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass15;
										}
									else									
									d3<<nic<<"\n";
									d3<<t.hours<<"\n";
									d3<<t.minutes<<"\n";
									d3<<t.day<<"\n";
								}
							}
							d3.close();
							break;
						}
							//open house 1 file and make object of tree and insert data according to it
						case 4:
						{	
							fstream d4;
							d4.open("D4.txt",ios::in | ios::out | ios::app);
							{
								if(!d4.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									time_t curr_time;
									curr_time = time(NULL);
									tm *tm_local = localtime(&curr_time);
									TIME t;
									t.hours=tm_local->tm_hour;
									t.minutes=tm_local->tm_min;
									t.day=tm_local->tm_mday;
									int count=0;
									pass16:
									cout<<"                           Enter Your CNIC Number(Eg. 4210112345678) :"<<endl;
									cout<<"                           ";
									cin>>nic;
									for (int i=0;i<nic.size();i++)
									{
										if (nic[i] >= 48 && nic[i] <=57 && nic.size()==13)
										{
										count++;
										}
									}
									
									if (count!=nic.size())
									{
										cout << "Follow Correct Format Please\n";
										count=0;
										goto pass16;
										}
									else							
									d4<<nic<<"\n";
									d4<<t.hours<<"\n";
									d4<<t.minutes<<"\n";
									d4<<t.day<<"\n";	
								}
							}
							d4.close();
							
							break;
						}
							//open house 1 file and make object of tree and insert data according to it
						default:
							cout<<"                           Invalid";
					}
					break;
				default:
					cout<<"                           Not Found";
			}
			break;
		}
		case 2:
			{
			
			node objj[50];
			string cnic;
			string checkcnic;
			int h,min,mday;
			cout<<"\n";
			cout<<"                           Enter Your Area Of Residence:"<<endl;
			cout<<"                           A-B-C-D"<<endl;
			cout<<"                           ";
			cin>>area;
			cout<<"                           Enter Your House Number:"<<endl;
			cout<<"                           1-2-3-4"<<endl;
			cout<<"                           ";
			cin>>hn;
			cout<<"                           Enter CNIC Number To Search:"<<endl;
			cout<<"                           ";
			cin>>checkcnic;
			cout<<"\n";
			switch(area){
				case 'A':
					switch(hn){
						case 1:
						{
							ifstream a1;
							a1.open("A1.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}
									obj.inorder(root);
									cout<<endl;
									object=obj.Search(checkcnic);
									
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << " = " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}
											
									}
								}
							a1.close();
							break;
						}
							//open house 1 file and make object of tree and insert and search data according to it
						case 2:
							{
								ifstream a1;
								a1.open("A2.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);									
										i++;
									}
									obj.inorder(root);
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}
								}
							}
							a1.close();
					    }
							break;
							//open house 1 file and make object of tree and insert and search data according to it
						case 3:
							{
								ifstream a1;
								a1.open("A3.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);	
										i++;
									}  
									obj.inorder(root);
									
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									} 
								}
							}
							a1.close();
							break;
							}//open house 1 file and make object of tree and insert and search data according to it
						case 4:
							{
								ifstream a1;
							a1.open("A4.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}  
									obj.inorder(root);
									
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}
								}
							}
							a1.close();
					    }
							break;
							//open house 1 file and make object of tree and insert and search data according to it
						default:{
							cout<<"                           Invalid!";
							break;
						}
					}
					break;
				case 'B':
					switch(hn){
						case 1:
						{
								ifstream a1;
							a1.open("B1.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}  
									obj.inorder(root);
									
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}  
								}
							}
							a1.close();
							break;
						}
							//open house 1 file and make object of tree and insert and search data according to it
						case 2:
							{
								ifstream a1;
								a1.open("B2.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}	
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}  
									obj.inorder(root);
									
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}
								}							
							}
							a1.close();
					    }
							break;
							//open house 1 file and make object of tree and insert and search data according to it
						case 3:
							{
								ifstream a1;
								a1.open("B3.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}  
									obj.inorder(root);
									obj.inorder(root);
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}  
								}
							}
							a1.close();
							break;
							}//open house 1 file and make object of tree and insert and search data according to it
						case 4:
							{
								ifstream a1;
								a1.open("B4.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}  
									obj.inorder(root);
									
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									} 									
								}
							}
							a1.close();
					    }
							break;
							//open house 1 file and make object of tree and insert and search data according to it
						default:{
							cout<<"                           Invalid!";
							break;
						}
					}
					break;
				case 'C':
					switch(hn)
					{
						case 1:
							{
							ifstream a1;
							a1.open("C1.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}		
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}  
									obj.inorder(root);
									
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}
								}
							}
							a1.close();
							break;
						}
							//open house 1 file and make object of tree and insert and search data according to it
						case 2:
							{
								ifstream a1;
								a1.open("C2.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}  
									obj.inorder(root);
									
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}
								}
							}
							a1.close();
					    }
							break;
							//open house 1 file and make object of tree and insert and search data according to it
						case 3:
							{
								ifstream a1;
								a1.open("C3.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}  
									obj.inorder(root);
									
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}
								}
							}
							a1.close();
							break;
							}//open house 1 file and make object of tree and insert and search data according to it
						case 4:
							{
								ifstream a1;
								a1.open("C4.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}  
									obj.inorder(root);
									
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}
								}
							}
							a1.close();
					    }
							break;
						default:
						{
							cout<<"                           Invalid!";
							break;
						}	
					}
				case 'D':
					switch(hn)
					{
						case 1:
							{
								ifstream a1;
								a1.open("D1.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}  
									obj.inorder(root);
									
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}  
								}
							}
							a1.close();
							break;
						}
						case 2:
							{
								ifstream a1;
								a1.open("D2.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}	
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);		
										i++;
									}  
									obj.inorder(root);
									
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}					
								}
							}
							a1.close();
					    }
							break;
							//open house 1 file and make object of tree and insert and search data according to it
						case 3:
							{
								ifstream a1;
								a1.open("D3.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;
										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}  
									obj.inorder(root);
									obj.inorder(root);
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}
								}
							}
							a1.close();
							break;
							}//open house 1 file and make object of tree and insert and search data according to it
						case 4:
							{
								ifstream a1;
								a1.open("D4.txt",ios::in | ios::out | ios::app);
							{
								if(!a1.is_open())
								{
									cout<<"                           Error While Opening File";
								}
								else
								{
									bst obj;
									node *object;
									int i=0;
									while(! a1.eof()){
     									a1 >> cnic >> h >> min >> mday ;

										objj[i].data = cnic;
										objj[i].tim.hours = h;
										objj[i].tim.minutes = min;
										objj[i].tim.day = mday;
										obj.insert(root,objj[i].data,objj[i].tim);
										i++;
									}  
									obj.inorder(root);
									
									cout<<endl;
									object=obj.Search(checkcnic);
									if(object!=NULL)
									{
										time_t curr_time;
										curr_time = time(NULL);
										tm *tm_local = localtime(&curr_time);
										TIME t2,difference;
										t2.hours=tm_local->tm_hour;
										t2.minutes=tm_local->tm_min;
										t2.day=tm_local->tm_mday;
										computeTimeDifference(object->tim, t2, &difference);
										cout << endl << "                           Time Difference:" << t2.hours << ":" << t2.minutes << " day " << t2.day;
    									cout << "  -  " << object->tim.hours << ":" << object->tim.minutes << " day " << object->tim.day;
    									cout << "  =  " << difference.hours << ":" << difference.minutes << " day " << difference.day<<endl;  
    									cout<<"\n";
									}
									else{
										cout<<"                           Not Found"<<endl;
										cout<<"                           Make Sure You Have Inputed This CNIC Number:"<<endl;
									}															
								}							
							}
							
							a1.close();
					    }
							break;	
						default:{
							cout<<"                           Invalid:"<<endl;
							break;
						}	
					}
					
				default:
					cout<<"                           Invalid:"<<endl;
			}
			break;
		}
		case 3:
		{
			string ar;
			linklist l;
			cout<<"\n";
			cout<<"                           Enter Area You Are Interested In:"<<endl;
			cout<<"                           ";
			cin>>ar;
			int flag=0;
			fstream area,k;
			area.open("Area.txt");
			{
				if(!area.is_open())
				{
					cout<<"                           Error Opening File"<<endl;
				}
				else
				{
					while(!area.eof())
					{
						string a;
						area>>a;
						l.addtotail(a);	
					}
					nod *start=l.head;
					while(start!=NULL)
					{
						if(start->data==ar)
						{
							flag=1;
						}
						start=start->next;
					}
					if(flag==0)
					{
						cout<<"                           Area Unavailable:"<<endl;
					}
					else
					{
					
					if(l.head->data==ar)
						{
							fstream x;
							x.open("CoveredAreas.csv",ios::in | ios::out | ios::app);
							{
								if(!x.is_open())
								{
									cout<<"                           Error While Opening Covered Areas:"<<endl;
								}
								else
								{
						    	cout<<"                           Enter Approximate Number Of Days Ration Will Last:"<<endl;
						    	cout<<"                           ";
								int days;
								cin>>days;
								l.head->score=days;
								x<<l.head->data<<" , "<<l.head->score<<endl;
								cout<<"                           Area Covered Successfully:"<<endl;
								flag=1;
							    }
							}
							x.close();
						}
					else                           
					{
						nod *temp=l.head;
					while(temp!=NULL)
					{
						if(temp->next->data==ar)
						{
							fstream op;
							op.open("CoveredAreas.csv",ios::in | ios::out | ios::app);
							{
								if(!op.is_open())
								{
									cout<<"                           Error While Opening Covered Areas"<<endl;
								}
								else
								{
									cout<<"                           Enter Approximate Number Of Days Ration Will Last:"<<endl;
									cout<<"                           ";
									int days;
									cin>>days;
									temp->next->score=days;
									op<<temp->next->data<<" , "<<temp->next->score<<endl;
									cout<<"                           Area Covered Successfully"<<endl;
									flag=1;
								}
								op.close();
							}
//							nod *tmp=temp->next;
//							temp->next=temp->next->next;
//							delete tmp;
							break;
						}
						temp=temp->next;
					}
					}
				}	
				}
			}
			area.close();
			k.open("Area.txt");
			{
				if(!k.is_open())
				{
					cout<<"                           Error While Opening Area.txt"<<endl;
				}
				else
				{
					l.head=l.ascendingsort();
					nod *t=l.head;
				
			        while(t!=l.tail->next)
			        { 
			            if(t->data==ar)
			            {
			            	t=t->next;
						}
						else if(t->data=="\n")
						{
							t=t->next;
						}
			            else
			            {
			            	k<<t->data<<endl;
				            t=t->next;
						}    
			        }
				}	
			}	
			k.close();
			while(l.head!=NULL)
			{
				nod *p=l.head;
				l.head=l.head->next;
				delete p;
				p=NULL;
			}
		}
		break;
	case 4:
			{
				int a,b,c;
				float count=0;
				string s;
				linklist x;
				ofstream f;
				f.open("RiskFactor.csv");
				{
					if(!f.is_open())
					{
						cout<<"\nError opening RiskFactor file"<<endl;
					}
					else
					{
						fstream d;
						d.open("A1.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("A1",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("A1",count);
				
							}
						}
						d.close();
						count=0;
						d.open("A2.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("A2",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("A2",count);
							}
						}
						d.close();
						count=0;
						d.open("A3.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("A3",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("A3",count);
							}
						}
						d.close();
						count=0;
						d.open("A4.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("A4",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("A4",count);
							}
						}
						d.close();
						count=0;
						d.open("B1.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("B1",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("B1",count);
							}
						}
						d.close();
						count=0;
						d.open("B2.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("B2",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("B2",count);
							}
						}
						d.close();
						count=0;
						d.open("B3.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("B3",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("B3",count);
							}
						}
						d.close();
						count=0;
						d.open("B4.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("B4",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("B4",count);
							}
						}
						d.close();
						count=0;
						d.open("C1.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("C1",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("C1",count);
							}
						}
						d.close();
						count=0;
						d.open("C2.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("C2",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("C2",count);
							}
						}
						d.close();
						count=0;
						d.open("C3.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("C3",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("C3",count);
							}
						}
						d.close();
						count=0;
						d.open("C4.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("C4",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("C4",count);
							}
						}
						d.close();
						count=0;
						d.open("D1.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("D1",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("D1",count);
							}
						}
						d.close();
						count=0;
						d.open("D2.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("D2",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("D2",count);
							}
						}
						d.close();
						count=0;
						d.open("D3.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("D3",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("D3",count);
							}
						}
						d.close();
						count=0;
						d.open("D4.txt");
						{
							if(!d.is_open())
							{
								x.addtotalin("D4",0);
							}
							else
							{
								while(!d.eof())
								{
									d>>s;
									d>>a;
									d>>b;
									d>>c;
									count++;
								}
								count--;
								count=(count/6)*100;
								x.addtotalin("D4",count);
							}
						}
						d.close();
						x.head=x.descendingsort();
						nod *t=x.head;
						x.display(t);
					}
					}
				f.close();
				break;
			}
	}
}while(opt!=5);
cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n"<<endl;
cout<<"                           SOFTWARE CREATED BY:IBAD, HAMMAD, AMMAR, HASAN"<<endl;
cout<<"                           (-: Copyrights :-)"<<endl;
                           
}
