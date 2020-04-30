#include "list.h"

void show_menu(){
  printf("\n\nMain Menu\n");
  printf("---------\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end(if it already exists, do not insert)\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n");
  printf("\nPlease enter the alphabet of the operation you would like to perform  ");
}

int main(void)
{
  List_ptr list = create_list();
  char operation;
  int value, position;

  while(operation != 'm'){
    show_menu();
    scanf("%c",&operation);
    fflush(stdin);
    switch (operation)
    {
      case 'a':
        
        printf("Enter a value: \n");
        scanf("%d",&value);
        fflush(stdin);
        add_to_end(list,value);
        break;

      case 'b':
        printf("Enter a value: \n");
        scanf("%d",&value);
        fflush(stdin);
        add_to_start(list,value);
        break;

      case 'c':
        printf("Enter a value and position: \n");
        scanf("%d %d",&value,&position);
        fflush(stdin);
        insert_at(list,value,position);
        break;

      case 'd':
        printf("Enter a value: \n");
        scanf("%d",&value);
        fflush(stdin);
        add_unique(list,value);
        break;

      case 'e':
        remove_from_start(list);
        break;

      case 'l':
        display(list);

      default:
        break;
      }
  }
  return 0;
}