/*
 * 009_rq.c
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
  struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_node(struct node *);


int main(int argc, char *argv[])
{
  int option;

  do
  {
    printf("\n\n *****MAIN MENU*****");
    printf("\n 1: Create a list of Students");
    printf("\n 2: Display the list");
    printf("\n 3: Delete a given node");
    printf("\n 4: EXIT");
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
      case 3:
        start = delete_node(start);
        break;
    }
  }while(option !=4);
  getchar();

  return 0;
}

struct node *create_ll(struct node *start)
{
  struct node *new_node, *ptr;
  int num;
  char name[20];
  printf("\n Enter -1 to end");
  while(num!=-1)
  {
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->code = num;
    memset(new_node->name, '\0', sizeof(new_node->name));
    strcpy(new_node->name, name);
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
    getchar();
    if (num == -1) {
      continue;
    }
    printf(" Enter the name: ");
    fgets(name, sizeof(name), stdin);
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
    printf("\t %d", ptr->code);
    printf("\t %s\n", ptr->name);
    ptr = ptr->next;
  }
  return start;
}
struct node *delete_beg(struct node *start)
{
  struct node *ptr;
  ptr = start;
  start = start->next;
  free(ptr);
  return start;
}
struct node *delete_node(struct node *start)
{
  struct node *ptr, *preptr;
  int val;
  printf("\n Enter the code of the student which has to be deleted: ");
  scanf("%d", &val);
  ptr = start;
  if(ptr->code == val)
  {
    start = delete_beg(start);
    return start;
  } else {
    while(ptr->code != val)
    {
      preptr = ptr;
      ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
  }
}
