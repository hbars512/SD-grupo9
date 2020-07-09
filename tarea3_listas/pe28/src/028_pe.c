/*
 * 028_pe.c
 *
 *  Created on: Jul 8, 2020
 *      Author: grupo 9
 */


#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct node
{
  int code;
  char name[20];
  float salary;
  struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);


int main(int argc, char *argv[])
{
  int option;

  do
  {
    printf("\n\n *****MAIN MENU*****");
    printf("\n 1: Create a list of Employees");
    printf("\n 2: Display the list");
    printf("\n 3: EXIT");
    printf("\n\n Enter your option: ");
    scanf("%d", &option);

    switch (option) {
      case 1:
        start = create_ll(start);
        printf("\n LINKED LIST CREATED");
        break;
      case 2:
        start = display(start);
        break;
    }
  }while(option !=3);
  getchar();

  return 0;
}

struct node *create_ll(struct node *start)
{
  struct node *new_node, *ptr;
  int num;
  char name[20];
  float salary;
  printf("\n Enter -1 to end");
  while(num!=-1)
  {
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->code = num;
    memset(new_node->name, '\0', sizeof(new_node->name));
    strcpy(new_node->name, name);
    new_node->salary = salary;
    if(start==NULL)
    {
      new_node->next = NULL;
      start = new_node;
    } else {
      ptr = start;
      while(ptr->next != NULL)
        ptr = ptr->next;
      ptr->next = new_node;
      new_node->next = NULL;
    }
    printf("\n Enter the code: ");
    scanf("%d", &num);
    if (num == -1) {
      continue;
    }
    getchar();
    printf(" Enter the name of employee: ");
    fgets(name, sizeof(name), stdin);
    printf(" Enter the salary: ");
    scanf("%f", &salary);
  }
  return start;
}
struct node *display(struct node *start)
{
  struct node *ptr;
  ptr = start;
  while(ptr != NULL)
  {
    if (ptr->code == 0) {
      ptr = ptr->next;
      continue;
    }
    printf("\t %d\n", ptr->code);
    printf("\t %s", ptr->name);
    printf("\t %.2f\n\n", ptr->salary);
    ptr = ptr->next;
  }
  return start;
}
