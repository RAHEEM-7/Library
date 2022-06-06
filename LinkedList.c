#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct date
{
	int day;
	int month;
	int yr;
};

struct location
{
	int hall_no;
	int rack_no;
	int row_no;
};

typedef struct book_tag
{
	char Name[50];
	char sub[50];
	char Author[50];
	char Acc_No[20];
	int yop;
	char print_type[20];
	char status[10];
	struct location loc_book;
	struct date issued,renew;
	struct book_tag* next;
}book;

typedef struct member_tag
{
	char Name[50];
	char Dep[50];
	char ID[15];
	int nob;
	char designation[10];
	book* iss_books;
	struct member_tag* next;
}member;

//Declaration of Functions
book* makingnode_book(char* Name,char* sub,char* Author,char* Acc_No,int yop,char* print_type,char* status);
member* makingnode_member(char* Name,char* Dep,char* ID,int nob,char* designation,book* iss_books);
book* insertbook_atStart(book* books,char* Name,char* sub,char* Author,char* Acc_No,int yop,char* print_type,char* status);
member* insertmember_atStart(member* mem,char* Name,char* Dep,char* ID,int nob,char* designation,book* iss_books);
book* merge_books(book* books1,book* books2);
book* divide_book(book* books);
book* sort_books(book* books);
void search_book_name(book* books,char* Name);
void search_book_Author(book* books,char* Author_name);
member* ADD_Student(member* stu,book** books);
member* ADD_Faculty(member* fac,book** books);
void Max_No_of_books(member* mem);
book* insert_book(book* books);
member* divide_member(member* mem);
member* sort_member(member* mem);
member* merge_member(member* mem1,member* mem2);
member*	merge_stu_and_fac(member* stu,member* fac);
book* Renew_date_stu(book* ptr);
book* Renew_date_fac(book* ptr);
int Fine(member* ptr,int YEAR,int MON,int DAY);
void Max_Fine(member* mem);
member* Issue_book_stu(member* stu,book** books);
member* Issue_book_fac(member* fac,book** books);

// MAIN
int main()
{
	book* books;
	member* student;
	member* faculty;
	books = NULL;
	student = NULL;
	faculty = NULL;
	// Initially inserting some Books in the books linked list.
	char Name[] = "C Programming", sub[] = "Coding", Author[] = "Yashwanth", Acc_No[] = "1", print_type[] = "NewBook",status[] = "available" ;
	int yop = 2015;
	books = insertbook_atStart(books,Name,sub,Author,Acc_No,yop,print_type,status); // book1
	// Setting Location of book
	books->loc_book.hall_no = 1;
	books->loc_book.rack_no = 1;
	books->loc_book.row_no = 10;

	strcpy(Name,"JAVA"); strcpy(sub,"Coding"); strcpy(Author,"Vijay"); strcpy(Acc_No,"2"); strcpy(print_type,"NewBook"); yop = 2014;
	books = insertbook_atStart(books,Name,sub,Author,Acc_No,yop,print_type,status); // book2
	//Setting Location of book
	books->loc_book.hall_no = 1;
	books->loc_book.rack_no = 2;
	books->loc_book.row_no = 12;

	strcpy(Name,"C Programming"); strcpy(sub,"Coding"); strcpy(Author,"Yashwanth"); strcpy(Acc_No,"3"); strcpy(print_type,"NewPrint"); yop = 2016;
	books = insertbook_atStart(books,Name,sub,Author,Acc_No,yop,print_type,status); // book3
	//  Setting Location of book
	books->loc_book.hall_no = 1;
	books->loc_book.rack_no = 3;
	books->loc_book.row_no = 15;

	strcpy(Name,"Avadhanulu"); strcpy(sub,"Physics"); strcpy(Author,"Avadhan"); strcpy(Acc_No,"4"); strcpy(print_type,"NewBook"); yop = 2014;
	books = insertbook_atStart(books,Name,sub,Author,Acc_No,yop,print_type,status); //book4
	// Setting Location of book
	books->loc_book.hall_no = 1;
	books->loc_book.rack_no = 4;
	books->loc_book.row_no = 8;

	strcpy(Name,"Jain"); strcpy(sub,"Maths"); strcpy(Author,"Rohit"); strcpy(Acc_No,"5"); strcpy(print_type,"NewBook"); yop = 2018;
	books = insertbook_atStart(books,Name,sub,Author,Acc_No,yop,print_type,status); //book5
	// Setting Location of book
	books->loc_book.hall_no = 1;
	books->loc_book.rack_no = 5;
	books->loc_book.row_no = 11;

	strcpy(Name,"Jain"); strcpy(sub,"Chemistry"); strcpy(Author,"Iyengar"); strcpy(Acc_No,"6"); strcpy(print_type,"NewBook"); yop = 2017;
	books = insertbook_atStart(books,Name,sub,Author,Acc_No,yop,print_type,status); //book6
	// Setting Location of book
	books->loc_book.hall_no = 2;
	books->loc_book.rack_no = 10;
	books->loc_book.row_no = 10;

	strcpy(Name,"Learn Mechanics"); strcpy(sub,"Mechanics"); strcpy(Author,"Ratnesh"); strcpy(Acc_No,"7"); strcpy(print_type,"NewBook"); yop = 2015;
	books = insertbook_atStart(books,Name,sub,Author,Acc_No,yop,print_type,status); //book7
	// Setting Location of book
	books->loc_book.hall_no = 2;
	books->loc_book.rack_no = 1;
	books->loc_book.row_no = 10;

	strcpy(Name,"Learn C"); strcpy(sub,"Coding"); strcpy(Author,"Kerning"); strcpy(Acc_No,"8"); strcpy(print_type,"NewBook"); yop = 2012;
	books = insertbook_atStart(books,Name,sub,Author,Acc_No,yop,print_type,status); // book8
	// Setting Location of book
	books->loc_book.hall_no = 2;
	books->loc_book.rack_no = 2;
	books->loc_book.row_no = 4;

	strcpy(Name,"Electric"); strcpy(sub,"Electrical"); strcpy(Author,"Virat"); strcpy(Acc_No,"9"); strcpy(print_type,"NewBook"); yop = 2000;
	books = insertbook_atStart(books,Name,sub,Author,Acc_No,yop,print_type,status); // book9
	// Setting Location of book
	books->loc_book.hall_no = 2;
	books->loc_book.rack_no = 3;
	books->loc_book.row_no = 15;

	strcpy(Name,"Jain Iyengar"); strcpy(sub,"Maths"); strcpy(Author,"Iyengar"); strcpy(Acc_No,"10"); strcpy(print_type,"NewBook"); yop = 2002;
	books = insertbook_atStart(books,Name,sub,Author,Acc_No,yop,print_type,status); // book10
	// Setting Location of book
	books->loc_book.hall_no = 2;
	books->loc_book.rack_no = 7;
	books->loc_book.row_no = 14;

	// Initially inserting some students in student linked list.
	// Inserting student no 1.
	book* bok1 = NULL;
	char name[] = "Raheem",Dep[] = "CSE", ID[] = "BT19CSE067",designation[] = "Student";
	int nob = 0;
	student = insertmember_atStart(student,name,Dep,ID,nob,designation,bok1);

	// inserting student no 2.
	book* bok2 = NULL;
	strcpy(Acc_No,"6");
	book* ptr;
	ptr = books;
	int flag = 1;
	while((ptr != NULL) && (flag == 1))
	{
		if(strcmp(ptr->Acc_No,Acc_No)==0)
		{
			strcpy(ptr->status,"issued");
			ptr->issued.day = 2 ;
			ptr->issued.month = 5;
			ptr->issued.yr = 2020;
			ptr = Renew_date_stu(ptr);
			printf("Renew date of book issued by Vijit : ");
			printf("%d-",ptr->renew.day);
			printf("%d-",ptr->renew.month);
			printf("%d\n",ptr->renew.yr);
			bok2 = insertbook_atStart(bok2,ptr->Name,ptr->sub,ptr->Author,ptr->Acc_No,ptr->yop,ptr->print_type,ptr->status);
			bok2->issued.day = ptr->issued.day;
			bok2->issued.month = ptr->issued.month;
			bok2->issued.yr = ptr->issued.yr;
			bok2->renew.day = ptr->renew.day;
			bok2->renew.month = ptr->renew.month;
			bok2->renew.yr = ptr->renew.yr;
			flag = 0;
		}
		ptr = ptr->next;
	}
	strcpy(name,"Vijit"); strcpy(Dep,"CHEM"); strcpy(ID,"BT19CHEM082"); nob = 1;
	student = insertmember_atStart(student,name,Dep,ID,nob,designation,bok2);

	// inserting student no 3.
	flag = 1;
	book* bok3 = NULL;
	char Acc_No1[] = "1";char Acc_No2[] = "5";
	ptr = books;
	int flag1 = 1,flag2 = 1;
	printf("Renew dates of books issued by Gowtham : ");
	while((ptr != NULL) && (flag == 1))
	{
		if(strcmp(ptr->Acc_No,Acc_No1)==0)
		{
			strcpy(ptr->status,"issued");
			ptr->issued.day = 2;
			ptr->issued.month = 2;
			ptr->issued.yr = 2020;
			ptr = Renew_date_stu(ptr);
			printf("%d-",ptr->renew.day);
			printf("%d-",ptr->renew.month);
			printf("%d , ",ptr->renew.yr);
			bok3 = insertbook_atStart(bok3,ptr->Name,ptr->sub,ptr->Author,ptr->Acc_No,ptr->yop,ptr->print_type,ptr->status);
			bok3->issued.day = ptr->issued.day;
			bok3->issued.month = ptr->issued.month;
			bok3->issued.yr = ptr->issued.yr;
			bok3->renew.day = ptr->renew.day;
			bok3->renew.month = ptr->renew.month;
			bok3->renew.yr = ptr->renew.yr;
			flag1 = 0;
		}
		else if(strcmp(ptr->Acc_No,Acc_No2)==0)
		{
			strcpy(ptr->status,"issued");
			ptr->issued.day = 2;
			ptr->issued.month = 2 ;
			ptr->issued.yr = 2020;
			ptr = Renew_date_stu(ptr);
			printf("%d-",ptr->renew.day);
			printf("%d-",ptr->renew.month);
			printf("%d\n",ptr->renew.yr);
			bok3 = insertbook_atStart(bok3,ptr->Name,ptr->sub,ptr->Author,ptr->Acc_No,ptr->yop,ptr->print_type,ptr->status);
			bok3->issued.day = ptr->issued.day;
			bok3->issued.month = ptr->issued.month;
			bok3->issued.yr = ptr->issued.yr;
			bok3->renew.day = ptr->renew.day;
			bok3->renew.month = ptr->renew.month;
			bok3->renew.yr = ptr->renew.yr;
			flag2 = 0;
		}
		if((flag1 == 0) && (flag2 == 0))
		{
			flag = 0;
		}
		ptr = ptr->next;
	}
	strcpy(name,"Gowtham"); strcpy(Dep,"CSE"); strcpy(ID,"BT19CSE033"); nob = 2;
	student = insertmember_atStart(student,name,Dep,ID,nob,designation,bok3);

	// Initially inserting some faculty members in faculty linked list.
	// inserting faculty member 1.
	book* bok4 = NULL;
	strcpy(name,"Preetham"); strcpy(Dep,"META"); strcpy(ID,"PRMETA143"); strcpy(designation,"Faculty");
 	nob = 0;
	faculty = insertmember_atStart(faculty,name,Dep,ID,nob,designation,bok4);

	//inserting faculty member 2.
	book* bok5 = NULL;
	strcpy(Acc_No,"4");
	ptr = books;
	flag = 1;
	while((ptr != NULL) && (flag == 1))
	{
		if(strcmp(ptr->Acc_No,Acc_No)==0)
		{
			strcpy(ptr->status,"issued");
			ptr->issued.day = 4;
			ptr->issued.month = 10;
			ptr->issued.yr = 2020;
			ptr = Renew_date_fac(ptr);
			printf("Renew date of book issued by Rahul : ");
			printf("%d-",ptr->renew.day);
			printf("%d-",ptr->renew.month);
			printf("%d\n",ptr->renew.yr);
			bok5 = insertbook_atStart(bok5,ptr->Name,ptr->sub,ptr->Author,ptr->Acc_No,ptr->yop,ptr->print_type,ptr->status);
			bok5->issued.day = ptr->issued.day;
			bok5->issued.month = ptr->issued.month;
			bok5->issued.yr = ptr->issued.yr;
			bok5->renew.day = ptr->renew.day;
			bok5->renew.month = ptr->renew.month;
			bok5->renew.yr = ptr->renew.yr;
			flag = 0;
		}
		ptr = ptr->next;
	}
	strcpy(name,"RAHUL"); strcpy(Dep,"PHYSICS"); strcpy(ID,"PRPHY333"); strcpy(designation,"Faculty"); nob = 1;
	faculty = insertmember_atStart(faculty,name,Dep,ID,nob,designation,bok5);

	//inserting faculty member 3.
	flag = 1;
	book* bok6 = NULL;
	strcpy(Acc_No1,"7"); strcpy(Acc_No2,"10");
	ptr = books;
	flag1 = 1;
	flag2 = 1;
	printf("Renew dates of books issued by Bhanu :");
	while((ptr != NULL) && (flag == 1))
	{
		if(strcmp(ptr->Acc_No,Acc_No1)==0)
		{
			strcpy(ptr->status,"issued");
			ptr->issued.day = 1;
			ptr->issued.month = 11;
			ptr->issued.yr = 2020;
			ptr = Renew_date_fac(ptr);
			printf("%d-",ptr->renew.day);
			printf("%d-",ptr->renew.month);
			printf("%d\n",ptr->renew.yr);
			bok6 = insertbook_atStart(bok6,ptr->Name,ptr->sub,ptr->Author,ptr->Acc_No,ptr->yop,ptr->print_type,ptr->status);
			bok6->issued.day = ptr->issued.day;
			bok6->issued.month = ptr->issued.month;
			bok6->issued.yr = ptr->issued.yr;
			bok6->renew.day = ptr->renew.day;
			bok6->renew.month = ptr->renew.month;
			bok6->renew.yr = ptr->renew.yr;
			flag1 = 0;
		}
		else if(strcmp(ptr->Acc_No,Acc_No2)==0)
		{
			strcpy(ptr->status,"issued");
			ptr->issued.day = 1;
			ptr->issued.month = 11;
			ptr->issued.yr = 2020;
			ptr = Renew_date_fac(ptr);
			printf("%d-",ptr->renew.day);
			printf("%d-",ptr->renew.month);
			printf("%d\n",ptr->renew.yr);
			bok6 = insertbook_atStart(bok6,ptr->Name,ptr->sub,ptr->Author,ptr->Acc_No,ptr->yop,ptr->print_type,ptr->status);
			bok6->issued.day = ptr->issued.day;
			bok6->issued.month = ptr->issued.month;
			bok6->issued.yr = ptr->issued.yr;
			bok6->renew.day = ptr->renew.day;
			bok6->renew.month = ptr->renew.month;
			bok6->renew.yr = ptr->renew.yr;
			flag2 = 0;
		}
		if((flag1 == 0) && (flag2 == 0))
		{
			flag = 0;
		}
		ptr = ptr->next;
	}
	strcpy(name,"Bhanu"); strcpy(Dep,"MECH"); strcpy(ID,"PRMECH122"); strcpy(designation,"Faculty"); nob = 2;
	faculty = insertmember_atStart(faculty,name,Dep,ID,nob,designation,bok6);

	//sorting books by using sort_books() function.
	books = sort_books(books);

	int state = 1;
	while(state == 1)
	{
		printf("\nEnter the following number to perform operation you want\n");
		printf("1:To search book by Name\n2:To search book by Author Name\n3:To Add student\n4:To Add Faculty\n");
		printf("5:To know students who issued max books\n6:To know faculty who issued max books\n7:To sort and display names of borrowers in descending order of no of books issued\n");
		printf("8:To Insert book\n9:To know the renew date of the book\n10:To know fine of student\n11:To know the fine of faculty\n12:To know the maximum fine of students\n");
		printf("13:To know the maximum fine of Faculty\n14:To issue a book if you are a student\n15:To issue a book if you are a faculty\n any other number:To exit\n");

		int c;
		scanf("%d",&c);

		switch(c)
		{
			case 1:
			{
				char NAME[50];
				printf("Enter the name of Book\n");
				scanf("%s",NAME);
				search_book_name(books,NAME);
				break;
			}
			case 2:
			{
				char NAME[50];
				printf("Enter the name of Author\n");
				scanf("%s",NAME);
				search_book_Author(books,NAME);
				break;
			}
			case 3:
			{
				student = ADD_Student(student,&books);
				break;
			}
			case 4:
			{
				faculty = ADD_Faculty(faculty,&books);
				break;
			}
			case 5:
			{
				Max_No_of_books(student);
				break;
			}
			case 6:
			{
				Max_No_of_books(faculty);
				break;
			}
			case 7:
			{
				student = sort_member(student);
				faculty = sort_member(faculty);
				member* mem;
				mem = merge_stu_and_fac(student,faculty);
				break;
			}
			case 8:
			{
				books = insert_book(books);
				break;
			}
			case 9:
			{
				printf("Enter the Accession Number of the book : ");
				char AcNo[20];
				scanf("%s",AcNo);
				book* p = books;
				int fl = 1;
				while((p !=  NULL) && (fl == 1))
				{
					if(strcmp(p->Acc_No,AcNo)==0)
					{
						char s[] = "issued";
						if(strcmp(p->status,s)==0)
						{
							printf("-------Renew Date is : ");
							printf("--------%d-%d-%d--------\n",p->renew.day,p->renew.month,p->renew.yr);
							fl = 0;
						}
						else
						{
							printf("--------Book is not issued----------\n");
							fl = 0;
						}
					}
					p = p->next;
				}
				if(fl == 1)
				{
					printf("--------Enter Proper Accession Number-------\n");
				}
				break;
			}
			case 10:
			{
				printf("Enter the current date\n");
				printf("Enter the year\n");
				int YEAR;
				scanf("%d",&YEAR);
				printf("Enter the month\n");
				int MON;
				scanf("%d",&MON);
    			printf("Enter the day\n");
				int DAY;
				scanf("%d",&DAY);
				printf("Enter the Student_ID : ");
				char S_ID[15];
				scanf("%s",S_ID);
				member* stu = student;
				int fl = 1;
				while((stu != NULL) && (fl == 1))
				{
					if(strcmp(stu->ID,S_ID)==0)
					{
						int fine;
						fine = Fine(stu,YEAR,MON,DAY);
						printf("-------------Fine = %d paise-------------",fine);
						fl = 0;
					}
					stu  = stu->next;
				}
				if(fl == 1)
				{
					printf("------Enter proper Student ID-------\n");
				}
				break;
			}
			case 11:
			{
				printf("Enter the current date\n");
				printf("Enter the year\n");
				int YEAR;
				scanf("%d",&YEAR);
				printf("Enter the month\n");
				int MON;
				scanf("%d",&MON);
    			printf("Enter the day\n");
				int DAY;
				scanf("%d",&DAY);
				printf("Enter the Faculty_ID : ");
				char F_ID[15];
				scanf("%s",F_ID);
				member* fac = faculty;
				int fl = 1;
				while((fac != NULL) && (fl == 1))
				{
					if(strcmp(fac->ID,F_ID)==0)
					{
						int fine;
						fine = Fine(fac,YEAR,MON,DAY);
						printf("---------Fine = %d----------",fine);
					}
					fac = fac->next;
				}
				if(fl = 0)
				{
					printf("--------Enter proper faculty ID---------\n");
				}
				break;
			}
			case 12:
			{
				Max_Fine(student);
				break;
			}
			case 13:
			{
				Max_Fine(faculty);
				break;
			}
			case 14:
			{
				student = Issue_book_stu(student,&books);
				break;
			}
			case 15:
			{
				faculty = Issue_book_fac(faculty,&books);
				break;
			}
			default:
			{
				state = 0;
				break;
			}
		}
	}
	return 0;
}
// making a node for book
book* makingnode_book(char* Name,char* sub,char* Author,char* Acc_No,int yop,char* print_type,char* status)
{
	book* bok;
	bok = (book*)malloc(sizeof(book));
	if(bok!=NULL)
	{
		strcpy(bok->Name,Name);
		strcpy(bok->sub,sub);
		strcpy(bok->Author,Author);
		strcpy(bok->Acc_No,Acc_No);
		bok->yop = yop;
		strcpy(bok->print_type,print_type);
		strcpy(bok->status,status);
		bok->next = NULL;
	}
	return bok;
}
// making a node for member
member* makingnode_member(char* Name,char* Dep,char* ID,int nob,char* designation,book* iss_books)
{
	member* mem;
	mem = (member*)malloc(sizeof(member));
	if(mem!= NULL)
	{
		strcpy(mem->Name,Name);
		strcpy(mem->Dep,Dep);
		strcpy(mem->ID,ID);
		mem->nob = nob;
		strcpy(mem->designation,designation);
		mem->iss_books = iss_books;
		mem->next = NULL;
	}
	return mem;
}

// to insert book at start
book* insertbook_atStart(book* books,char* Name,char* sub,char* Author,char* Acc_No,int yop,char* print_type,char* status)
{
	book* ptr;
	ptr = makingnode_book(Name,sub,Author,Acc_No,yop,print_type,status);
	ptr->next = books;
	books = ptr;
	return books;
}

// to insert book at start
member* insertmember_atStart(member* mem,char* Name,char* Dep,char* ID,int nob,char* designation,book* iss_books)
{
	member* ptr;
	ptr = makingnode_member(Name,Dep,ID,nob,designation,iss_books);
	ptr->next = mem;
	mem = ptr;
	return mem;
}
//merge function to merge two linked list of book
book* merge_books(book* books1,book* books2)
{
	book *result,*tail,*p,*q;
	p = books1;
	q = books2;
	if(strcmp((p->sub),(q->sub)) < 0)
	{
		result = books1;
		p = p->next;
	}
	else if(strcmp((p->sub),(q->sub)) == 0)
	{
		if(strcmp((p->Name),(q->Name)) < 0)
		{
			result = books1;
			p = p->next;
		}
		else if(strcmp((p->Name),(q->Name)) == 0)
		{
			if(strcmp((p->Author),(q->Author)) < 0)
			{
				result = books1;
				p = p->next;
			}
			else if(strcmp((p->Author),(q->Author)) == 0)
			{
				if(p->yop > q->yop )
				{
					result = books1;
					p = p->next;
				}
				else
				{
					result = books2;
					q = q->next;
				}
			}
			else
			{
				result = books2;
				q = q->next;
			}
		}
		else
		{
			result = books2;
			q = q->next;
		}
	}
	else
	{
		result = books2;
		q= q->next;
	}
	tail = result;
	while((p!= NULL) && (q!= NULL))
	{
		if(strcmp((p->sub),(q->sub)) < 0)
		{
			tail = tail->next = p;
			p = p->next;
		}
		else if(strcmp((p->sub),(q->sub)) == 0)
		{
			if(strcmp((p->Name),(q->Name)) < 0)
			{
				tail = tail->next = p;
				p = p->next;
			}
			else if(strcmp((p->Name),(q->Name)) == 0)
			{
				if(strcmp((p->Author),(q->Author)) < 0)
				{
					tail = tail->next = p;
					p = p->next;
				}
				else if(strcmp((p->Author),(q->Author)) == 0)
				{
					if(p->yop > q->yop)
					{
						tail = tail->next = p;
						p = p->next;
					}
					else
					{
						tail = tail->next = q;
						q = q->next;
					}
				}
				else
				{
					tail = tail->next = q;
					q = q->next;
				}
			}
			else
			{
				tail = tail->next = q;
				q = q->next;
			}
		}
		else
		{
			tail = tail->next = q;
			q= q->next;
		}
	}
	if(p!= NULL)
	{
		tail->next = p;
	}
	else
	{
		tail->next = q;
	}
	return result;
}
// divide function for book linked list
book* divide_book(book* books)
{
	book *slow,*fast,*result;
	slow = books;
	fast = books->next->next;
	while(fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast != NULL)
		{
			fast = fast->next;
		}
	}
	result = slow->next;
	slow->next = NULL;
	return result;
}

// sort functions for books
book* sort_books(book* books)
{
	book *head,*temp;
	head = books;
	if((head != NULL) && (head->next != NULL))
	{
		temp = divide_book(head);
		head = sort_books(head);
		temp = sort_books(temp);
		books = merge_books(head,temp);
	}
	return books;
}

//search book by name of book
void search_book_name(book* books,char* Name)
{
	book *ptr1,*ptr2;
	ptr1 = books;
	int count=0,flag=1;
	while((ptr1!= NULL) && (flag == 1))
	{
		if(strstr(ptr1->Name,Name))
		{
			printf("--------- Author of book is : %s ----------\n",ptr1->Author);
			ptr2 = ptr1;
			while(ptr2!=NULL)
			{
				if(strcmp(ptr1->Name,ptr2->Name)==0)
				{
					count++;
				}
				ptr2 = ptr2->next;
			}
			printf("-------- No of present Copies = %d -------\n",count);
			if(strcmp(ptr1->status,"issued")==0)
			{
				printf("--------Status is : 1---------\n");
			}
			else
			{
				printf("--------Status is : 0--------\n");
			}
			flag = 0;
		}
		ptr1 = ptr1->next;
	}
	if(flag == 1)
	{
		printf("\n--------Book is not present in library----------\n");
	}
}

// search book by Author name
void search_book_Author(book* books,char* Author_name)
{
	book *ptr1,*ptr2;
	ptr1 = books;
	int flag = 1;
	while((ptr1!= NULL) && (flag == 1))
	{
		if(strstr(ptr1->Author,Author_name))
		{
			ptr2=ptr1;
			printf("\n----------The books of Author are :---------\n");
			while(ptr2!=NULL)
			{
				if(strcmp(ptr1->Author,ptr2->Author)==0)
				{
					printf("-------%s------\n",ptr2->Name);
				}
				ptr2 = ptr2->next;
			}
			flag = 0;
		}
	}
	if(flag == 1)
	{
		printf("\n---------No Author is there with that Name--------\n");
	}
}

// To add a student to the student list
member* ADD_Student(member* stu,book** books)
{
	char Name[50],Dep[20],ID[15];
	int nob;
	printf("Enter the details of the student\n");
	printf("Enter the student name : ");
	scanf("%s",Name);
	printf("\nEnter the department of student : ");
	scanf("%s",Dep);
	printf("\nEnter the ID of student : ");
	scanf("%s",ID);
	printf("\nEnter the no of books issued Max 2,if creating just an account enter 0 : ");
	scanf("%d",&nob);
	book* bok = NULL;
	if(nob > 0)
	{
		int i = 0;
		while(i < nob)
		{
			printf("\nEnter the Accesion number of books that you have issued\n");
			char Acc[20];
			scanf("%s",Acc);
			int flag =1;
			book *ptr;
			ptr = *books;
			while((ptr != NULL) && (flag == 1))
			{
				if(strcmp(ptr->Acc_No,Acc)==0)	// To check the input book is there in our books list or not.
				{
					if(strcmp(ptr->status,"issued")!=0) // issue only when the book is available or Not-issued.
					{
						strcpy(ptr->status,"issued");			// changing the status of the book issued.
						printf("Enter the issued date in order of day, month , year :\n");
						scanf("%d",&ptr->issued.day);
						scanf("%d",&ptr->issued.month);
						scanf("%d",&ptr->issued.yr);
						ptr = Renew_date_stu(ptr);
						printf("---------Renew date is :");
						printf("%d-",ptr->renew.day);
						printf("%d-",ptr->renew.month);
						printf("%d\n",ptr->renew.yr);
						bok = insertbook_atStart(bok,ptr->Name,ptr->sub,ptr->Author,ptr->Acc_No,ptr->yop,ptr->print_type,ptr->status);
						bok->issued.day = ptr->issued.day;
						bok->issued.month = ptr->issued.month;
						bok->issued.yr = ptr->issued.yr;
						bok->renew.day = ptr->renew.day;
						bok->renew.month = ptr->renew.month;
						bok->renew.yr = ptr->renew.yr;
						flag = 0;
						i++;
					}
					else
					{
						printf("\n---------Book is already issued by others------\n");
					}
				}
				ptr = ptr->next;
			}
			if(flag == 1)
			{
				printf("\n---------Enter the proper Accession Number----------\n");
			}
		}
	}

	char S[] = "Student";
	stu = insertmember_atStart(stu,Name,Dep,ID,nob,S,bok);

	return stu;
}

// To Add Faculty member to the Faculty list
member* ADD_Faculty(member* fac,book** books)
{
	char Name[50],Dep[20],ID[15];
	int nob;
	printf("Enter the details of the faculty\n");
	printf("Enter the faculty name : ");
	scanf("%s",Name);
	printf("\nEnter the department of faculty : ");
	scanf("%s",Dep);
	printf("\nEnter the ID of faculty : ");
	scanf("%s",ID);
	printf("\nEnter the no of books issued Max 4,if creating just an account enter 0 : ");
	scanf("%d",&nob);
	book* bok = NULL;
	if(nob > 0)
	{

		int i = 0;
		while(i < nob)
		{
			printf("\nEnter the Accesion number of books that you have issued\n");
			char Acc_No[20];
			scanf("%s",Acc_No);
			int flag =1;
			book *ptr;
			ptr = *books;
			while((ptr != NULL) && (flag == 1))
			{
				if(strcmp(ptr->Acc_No,Acc_No)==0)	// To check the input book is there in our books list or not.
				{
					if(strcmp(ptr->status,"issued")!= 0 ) //issue only when the book is available or Not-issued.
					{
						strcpy(ptr->status,"issued");			// changing the status of the book issued.
						printf("Enter the issued date in ordder of day, month, year:\n");
						scanf("%d",&ptr->issued.day);
						scanf("%d",&ptr->issued.month);
						scanf("%d",&ptr->issued.yr);
						ptr = Renew_date_fac(ptr);
						printf("---------Renew date of the book is : ");
						printf("%d-",ptr->renew.day);
						printf("%d-",ptr->renew.month);
						printf("%d\n",ptr->renew.yr);
						bok = insertbook_atStart(bok,ptr->Name,ptr->sub,ptr->Author,ptr->Acc_No,ptr->yop,ptr->print_type,ptr->status);
						bok->issued.day = ptr->issued.day;
						bok->issued.month = ptr->issued.month;
						bok->issued.yr = ptr->issued.yr;
						bok->renew.day = ptr->renew.day;
						bok->renew.month = ptr->renew.month;
						bok->renew.yr = ptr->renew.yr;
						flag = 0;
					}
					else
					{
						printf("\n----------The book is already issued by others----------\n");
					}
				}
				ptr = ptr->next;
			}
			if(flag == 1)
			{
				printf("\n---------Enter the proper Accession Number----------\n");
			}
			i++;
		}
	}
	char F[] = "Faculty";
	fac = insertmember_atStart(fac,Name,Dep,ID,nob,F,bok);
	return fac;
}

void Max_No_of_books(member* mem)
{
	member* ptr;
	ptr = mem;
	int max = ptr->nob;
	while(ptr->next!=NULL)
	{
		if((ptr->next)->nob > max)
		{
			max = (ptr->next)->nob;
		}
		ptr = ptr->next;
	}
	printf("\n----------Maximum books issued are %d :-----------\n",max);
	printf("---------Members are --------\n");
	ptr = mem;
	while(ptr!=NULL)
	{
		if(ptr->nob == max)
		{
			printf("--------%s--------\n",ptr->Name);
		}
		ptr = ptr->next;
	}
}

// To insert a book according to order of sort
book* insert_book(book* books)
{
	char Name[50],sub[50],Author[50],print_type[20],Acc_No[20],status[20];
	int yop;
	printf("Enter the details of the book\n");
	printf("Enter the name of book : ");
	scanf("%s",Name);
	printf("\nEnter the subject of book : ");
	scanf("%s",sub);
	printf("\nEnter the Author name : ");
	scanf("%s",Author);
	printf("\nEnter NewPrint or NewBook : ");
	scanf("%s",print_type);
	printf("\nEnter the year of publication : ");
	scanf("%d",&yop);
	printf("\nEnter the Accession number : ");
	scanf("%s",Acc_No);
	printf("\nEnter the status of book : ");
	scanf("%s",status);
	book* bok;
	bok = makingnode_book(Name,sub,Author,Acc_No,yop,print_type,status);
	printf("Enter Hall No of book : ");
	scanf("%d",&bok->loc_book.hall_no);
	printf("Enter Rack No of book : ");
	scanf("%d",&bok->loc_book.rack_no);
	printf("Enter Row No of book : ");
	scanf("%d",&bok->loc_book.row_no);

	char P[] = "NewPrint" ;
	if(strcmp(print_type,P) == 0)
	{
		book *ptr,*prev = NULL;
		ptr = books;
		int flag=1;
		while((ptr!=NULL) && (flag == 1))
		{
			if((strcmp(ptr->Name,Name)==0) && (strcmp(ptr->sub,sub)==0) && (strcmp(ptr->Author,Author)==0))
			{
				if(ptr == books)
				{
					bok->next = books;
					books = bok;
				}
				else
				{
					prev->next = bok;
					bok->next = ptr;
				}
				flag = 0;
			}
			prev = ptr;
			ptr = ptr->next;
		}
	}
	else
	{
		book *ptr,*prev;
		ptr = books;
		int flag =1;
		while((ptr!=NULL) && (flag == 1))
		{
			if(strcmp(ptr->sub,sub)<0)
			{
				if(ptr == books)
				{
					bok->next = books;
					books = bok;
				}
				else
				{
					prev->next = bok;
					bok->next = books;
				}
				flag = 0;
			}
			else if(strcmp(ptr->sub,sub)==0)
			{
				if(strcmp(ptr->Name,Name)<0)
				{
					if(ptr == books)
					{
						bok->next = books;
						books = bok;
					}
					else
					{
						prev->next = bok;
						bok->next = ptr;
					}
					flag = 0;
				}
				else if(strcmp(ptr->Name,Name)==0)
				{
					if(strcmp(ptr->Author,Author)<0)
					{
						if(ptr == books)
						{
							bok->next = books;
							books = bok;
						}
						else
						{
							prev->next = bok;
							bok->next = ptr;
						}
						flag = 0;
					}
				}
			}
			prev = ptr;
			ptr = ptr->next;
		}
	}
	return books;
}

// To divide the member linked list
member* divide_member(member* mem)
{
	member *slow,*fast,*result;
	slow = mem;
	fast = mem->next->next;
	while(fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
		if(fast != NULL)
		{
			fast = fast->next;
		}
	}
	result = slow->next;
	slow->next = NULL;
	return result;
}

// To sort members based on number of books issued and alphabetical order of Name
member* sort_member(member* mem)
{
	member *head,*temp;
	head = mem;
	if((head!=NULL) && (head->next!=NULL))
	{
		temp = divide_member(head);
		head = sort_member(head);
		temp = sort_member(temp);
		mem = merge_member(head,temp);
	}
	return mem;
}

//To merge two linked lists of members
member* merge_member(member* mem1,member* mem2)
{
	member *p,*q,*result,*tail;
	p = mem1;
	q = mem2;
	if(mem1->nob > mem2->nob)
	{
		result = mem1;
		p = p->next;
	}
	else if(mem1->nob == mem2->nob)
	{
		if(strcmp(mem1->Name,mem2->Name) < 0)
		{
			result = mem1;
			p = p->next;
		}
		else
		{
			result = mem2;
			q = q->next;
		}
	}
	else
	{
		result = mem2;
		q = q->next;
	}
	tail = result;
	while((p!=NULL) && (q!=NULL))
	{
		if(p->nob > q->nob)
		{
			tail = tail->next = p;
			p = p->next;
		}
		else if(p->nob == q->nob)
		{
			if(strcmp(p->Name,q->Name) < 0)
			{
				result = mem1;
				p = p->next;
			}
			else
			{
				result = mem2;
				q = q->next;
			}
		}
		else
		{
			tail = tail->next = q;
			q = q->next;
		}
	}
	if(p!=NULL)
	{
		tail->next = p;
	}
	else
	{
		tail->next = q;
	}
	return result;
}

// To merge student list and Faculty list
member*	merge_stu_and_fac(member* stu,member* fac)
{
	member *p,*q,*result,*tail;
	p = stu;
	q = fac;
	if(stu->nob > fac->nob)
	{
		result = stu;
		p = p->next;
	}
	else
	{
		result = fac;
		q = q->next;
	}
	tail = result;
	while((p!=NULL) && (q!=NULL))
	{
		if(p->nob > q->nob)
		{
			tail = tail->next = p;
			p = p->next;
		}
		else
		{
			tail = tail->next = q;
			q = q->next;
		}
	}
	if(p!=NULL)
	{
		tail->next = p;
	}
	else
	{
		tail->next = q;
	}
	member* ptr;
	ptr = result;
	while(ptr != NULL)
	{
		printf("--------%s, ",ptr->Name);
		ptr = ptr->next;
	}
	return result;
}

// To find the renew date of book for student  ..considering he/she returns on 15th day from issuing the book.
book* Renew_date_stu(book* ptr)
{
	if(((ptr->issued.yr%4==0)&&(ptr->issued.yr%100!=0)||(ptr->issued.yr%400==0)) && (ptr->issued.month==02))
	{


	        if(ptr->issued.day<=15)
			{
		   		ptr->renew.day=ptr->issued.day+14;
		   		ptr->renew.month=02;
		   		ptr->renew.yr=ptr->issued.yr;
			}
	        else
			{
		   		ptr->renew.day=14-(29-ptr->issued.day);
		   		ptr->renew.month=03;
		   		ptr->renew.yr=ptr->issued.yr;
			}

	}
	else
	{
		if(ptr->issued.month==02)
		{
		  if(ptr->issued.day<=14)
		  {
		    ptr->renew.day=ptr->issued.day+14;
		    ptr->renew.month=02;
		    ptr->renew.yr=ptr->issued.yr;
		  }
		  else
	 	  {
		    ptr->renew.day=14-(28-ptr->issued.day);
		    ptr->renew.month=03;
		    ptr->renew.yr=ptr->issued.yr;
		  }
		}
		if(ptr->issued.month==12)
		{
		  if(ptr->issued.day<=17)
		  {
		    ptr->renew.day=ptr->issued.day+14;
		    ptr->renew.month=12;
		    ptr->renew.yr=ptr->issued.yr;
		  }
		  else
		  {
		    ptr->renew.day=14-(31-ptr->issued.day);
		    ptr->renew.month=01;
		    ptr->renew.yr=ptr->issued.yr+1;
		  }
		}
		if(ptr->issued.month==4||ptr->issued.month==06||ptr->issued.month==9||ptr->issued.month==11)
		{
			if(ptr->issued.day<=16)
			{
			   ptr->renew.day=ptr->issued.day+14;
			   ptr->renew.month=ptr->issued.month;
			   ptr->renew.yr=ptr->issued.yr;
			}
			else
			{
			    ptr->renew.day=14-(30-ptr->issued.day);
			    ptr->renew.month=ptr->issued.month+1;
			    ptr->renew.yr=ptr->issued.yr;
			}
		}
		else if(ptr->issued.month==1||ptr->issued.month==3||ptr->issued.month==5||ptr->issued.month==7||ptr->issued.month==8||ptr->issued.month==10)
		{
			if(ptr->issued.day<=17)
			{
			   ptr->renew.day=ptr->issued.day+14;
			   ptr->renew.month=ptr->issued.month;
			   ptr->renew.yr=ptr->issued.yr;
			}
			else
			{
			    ptr->renew.day=14-(31-ptr->issued.day);
				ptr->renew.month=ptr->issued.month+1;
			    ptr->renew.yr=ptr->issued.yr;
			}
		}
	}

	return ptr;
}

// To find the renew date of book for faculty  ..considering he/she returns on 31th day from issuing the book.
book* Renew_date_fac(book* ptr)
{
		if(((ptr->issued.yr%4==0)&&(ptr->issued.yr%100!=0)||(ptr->issued.yr%400==0)) && ((ptr->issued.month==2)||(ptr->issued.month==1)))
		{
			if(ptr->issued.month == 1)
			{
				ptr->renew.day = ptr->issued.day + 30;
				if(ptr->renew.day > 31 && ptr->renew.day <= 60)
				{
					ptr->renew.day = (ptr->renew.day)%31;
					ptr->renew.month = ptr->issued.month + 1;
				}
				else if(ptr->renew.day > 60)
				{
					ptr->renew.day = (ptr->renew.day)%30;
					ptr->renew.month = ptr->issued.month + 2;
				}
				else
				{
					ptr->renew.month = ptr->issued.month;
				}
				ptr->renew.yr = ptr->renew.yr;
			}
			else if(ptr->issued.month = 02)
			{
				ptr->renew.day = ptr->issued.day + 1;
				ptr->renew.month = ptr->issued.month + 1;
				ptr->renew.yr = ptr->issued.yr;
			}
		}
		else
		{
			if(ptr->issued.month == 1)
			{
				ptr->renew.day = ptr->issued.day + 30;
				if(ptr->renew.day > 31 && ptr->renew.day < 60)
				{
					ptr->renew.day = (ptr->renew.day)%31;
					ptr->renew.month = ptr->issued.month + 1;
				}
				else if(ptr->renew.day >=60)
				{
					ptr->renew.day = (ptr->renew.day)%30 + 1;
					ptr->renew.month = ptr->issued.month + 2;
				}
				else
				{
					ptr->renew.month = ptr->issued.month;
				}
				ptr->renew.yr = ptr->issued.yr;
			}
			else if(ptr->issued.month == 2)
			{
				ptr->renew.day = ptr->issued.day + 2;
				ptr->renew.month = ptr->issued.month + 1;
				ptr->renew.yr = ptr->issued.yr;
			}
			else if(ptr->issued.month == 12)
			{
				ptr->renew.day = ptr->issued.day + 30;
				if(ptr->renew.day > 31)
				{
					ptr->renew.day = (ptr->renew.day)%31;
					ptr->renew.month = 1;
					ptr->renew.yr = ptr->issued.yr + 1;
				}
				else
				{
					ptr->renew.month = ptr->issued.month;
					ptr->renew.yr = ptr->issued.yr;
				}
			}
			else if(ptr->issued.month==3||ptr->issued.month==5||ptr->issued.month==7||ptr->issued.month==8||ptr->issued.month==10)
			{
				ptr->renew.day = ptr->issued.day + 30;
				if(ptr->renew.day > 31)
				{
					ptr->renew.day = (ptr->renew.day)%31;
					ptr->renew.month = ptr->issued.month + 1;
				}
				else
				{
					ptr->renew.month = ptr->issued.month;
				}
				ptr->renew.yr = ptr->issued.yr;
			}
			else if(ptr->issued.month==4||ptr->issued.month==06||ptr->issued.month==9||ptr->issued.month==11)
			{
				ptr->renew.day = ptr->issued.day;
				ptr->renew.month = ptr->issued.month + 1;
				ptr->renew.yr = ptr->issued.yr;
			}

		}
		return ptr;
}

// To find the Fine
int Fine(member* ptr,int YEAR,int MON,int DAY)
{
	int fine=0;
	book* bok;
	bok = ptr->iss_books;
	while(ptr->iss_books != NULL)
	{
		if(((YEAR%4==0)&&(YEAR%100!=0))||YEAR%400==0)
		{
			if(ptr->iss_books->renew.month==MON)
			{
				fine=fine+(DAY-ptr->iss_books->renew.day)*50;
			}
			else if(ptr->iss_books->renew.month==2)
			{
				fine=fine+(29-ptr->iss_books->renew.day+DAY)*50;
			}
			else if(ptr->iss_books->renew.month==4||ptr->iss_books->renew.month==6||ptr->iss_books->renew.month==9||ptr->iss_books->renew.month==11)
			{
	   			fine=fine+(30-ptr->iss_books->renew.day+DAY)*50;
			}
			else
			{
				fine=fine+(31-ptr->iss_books->renew.day+DAY)*50;
			}
		}
		else
	   	{
			if(ptr->iss_books->renew.month==MON)
			{
				fine=fine+(DAY-ptr->iss_books->renew.day)*50;
			}
			else if(ptr->iss_books->renew.month==2)
			{
				fine=fine+(28-ptr->iss_books->renew.day+DAY)*50;
			}
			else if(ptr->iss_books->renew.month==4||ptr->iss_books->renew.month==6||ptr->iss_books->renew.month==9||ptr->iss_books->renew.month==11)
			{
	            fine=fine+(30-ptr->iss_books->renew.day+DAY)*50;
			}
			else
			{
				fine=fine+(31-ptr->iss_books->renew.day+DAY)*50;
			}
	   }
	   ptr->iss_books = ptr->iss_books->next;
	}
	ptr->iss_books = bok;
	return fine;
}

// To find who has maximum fine
void Max_Fine(member* mem)
{
	printf("Enter the current date\n");
	printf("Enter the year\n");
	int YEAR;
	scanf("%d",&YEAR);
	printf("Enter the month\n");
	int MON;
	scanf("%d",&MON);
    printf("Enter the day\n");
	int DAY;
	scanf("%d",&DAY);
	member* ptr = mem;
	int fine,max;
	max = Fine(ptr,YEAR,MON,DAY);
	ptr = ptr->next;
	while(ptr != NULL)
	{
		fine = Fine(ptr,YEAR,MON,DAY);
		if(fine > max)
		{
			max = fine;
		}
		ptr = ptr->next;
	}
	printf("---------Maximun Fine is %d --------- ",max);
	printf("\n-------These are members with Maximum Fine--------\n");
	ptr = mem;
	while(ptr != NULL)
	{
		fine = Fine(ptr,YEAR,MON,DAY);
		if(fine == max)
		{
			printf("--------%s, ",ptr->Name);
		}
		ptr = ptr->next;
	}														
}																	
																		
// To issue a book if you are a student
member* Issue_book_stu(member* stu,book** books)
{
	member* ptr = stu;
	printf("Enter student ID : ");
	char S_ID[20];
	scanf("%s",S_ID);
	while(ptr != NULL)
	{
		if(strcmp(ptr->ID,S_ID)==0)
		{
			if(ptr->nob < 2)
			{
				int fl = 1;
				while(fl == 1)
				{
					char AcNo[15];
					printf("\nEnter the Accession number of the book that you are issuing : ");
					scanf("%s",AcNo);
					book* p;
					p = *books;
					int flag = 1;
					while((p != NULL) && (flag == 1))
					{
						if(strcmp(p->Acc_No,AcNo)==0)
						{
							strcpy(p->status,"issued");
							printf("Enter the issued date \n");
							scanf("%d",&p->issued.day);
							scanf("%d",&p->issued.month);
							scanf("%d",&p->issued.yr);
							p = Renew_date_stu(p);
							ptr->iss_books = insertbook_atStart(ptr->iss_books,p->Name,p->sub,p->Author,p->Acc_No,p->yop,p->print_type,p->status);
							ptr->iss_books->issued.day = p->issued.day;
							ptr->iss_books->issued.month = p->issued.month;
							ptr->iss_books->issued.yr = p->issued.yr;
							ptr->iss_books->renew.day = p->renew.day;
							ptr->iss_books->renew.month = p->renew.month;
							ptr->iss_books->renew.yr = p->renew.yr;
							flag = 0;
						}
						p = p->next;
					}
					ptr->nob = ptr->nob + 1;
					if(ptr->nob < 2)
					{
						printf("If you want to issue another book press 1 :\n");
						int x;
						scanf("%d",&x);
						if(x == 1)
						{
							fl = 1;
						}
						else
						{
							fl = 0;
						}
					}
					else
					{
						printf("You issued Maximum number of books :\n");
						fl = 0;
					}
				}
			}
			else
			{
				printf("\nYou have already issued maximum number of books :\n");
			}
		}
		ptr = ptr->next;
	}
	return stu;
}

// To issue book if you are a faculty
member* Issue_book_fac(member* fac,book** books)
{
	member* ptr = fac;
	printf("Enter faculty ID : ");
	char F_ID[20];
	scanf("%s",F_ID);
	while(ptr != NULL)
	{
		if(strcmp(ptr->ID,F_ID)==0)
		{
			if(ptr->nob < 4)
			{
				int fl = 1;
				while(fl == 1)
				{
					char AcNo[15];
					printf("\nEnter the Accession number of the book that you are issuing : ");
					scanf("%s",AcNo);
					book* p;
					p = *books;
					int flag = 1;
					while((p != NULL) && (flag == 1))
					{
						if(strcmp(p->Acc_No,AcNo)==0)
						{
							strcpy(p->status,"issued");
							printf("Enter the issued date");
							scanf("%d",&p->issued.day);
							scanf("%d",&p->issued.month);
							scanf("%d",&p->issued.yr);
							p = Renew_date_stu(p);
							ptr->iss_books = insertbook_atStart(ptr->iss_books,p->Name,p->sub,p->Author,p->Acc_No,p->yop,p->print_type,p->status);
							ptr->iss_books->issued.day = p->issued.day;
							ptr->iss_books->issued.month = p->issued.month;
							ptr->iss_books->issued.yr = p->issued.yr;
							ptr->iss_books->renew.day = p->renew.day;
							ptr->iss_books->renew.month = p->renew.month;
							ptr->iss_books->renew.yr = p->renew.yr;
							flag = 0;
						}
						p = p->next;
					}
					ptr->nob = ptr->nob + 1;
					if(ptr->nob < 4)
					{
						printf("If you want to issue another book press 1 :\n");
						int x;
						scanf("%d",&x);
						if(x == 1)
						{
							fl = 1;
						}
						else
						{
							fl = 0;
						}
					}
					else
					{
						printf("You issued Maximum number of books :\n");
						fl = 0;
					}
				}
			}
			else
			{
				printf("\nYou have already issued maximum number of books :\n");
			}
		}
		ptr = ptr->next;
	}
	return fac;
}
