#include "list.h"

void show_menu(){
  printf("\nMain Menu\n");
  printf("---------\n");
  printf("(a) add a number to the end of the list\n");
  printf("(b) add a number to the start of the list\n");
  printf("(c) insert a number at a given position in the list\n");
  printf("(d) add a unique item on the list at the end(if it already exists, do not insert)\n");
  printf("(e) remove a number from the beginning of the list\n");
  printf("(f) remove a number from the end of the list\n");
  printf("(g) remove a number from a given position in the list\n");
  printf("(h) remove first occurrence of a number\n");
  printf("(i) remove all occurrences of a number\n");
  printf("(j) clear the whole list\n");
  printf("(k) check if a number exists in the list\n");
  printf("(l) display the list of numbers\n");
  printf("(m) exit\n");
  printf("---------------------------------------------------------------------\n");
  printf("Please enter the alphabet of the operation you would like to perform  ");
}

void display_status(status){
  if(status == 1){
    printf("Success");
  }else{
    printf("Failure");
  }
}


int main(void)
{
  List_ptr list = create_list();
  char operation;
  int value, position, index;
  Status status;
  while(operation != 'm'){
    show_menu();
    scanf("%c",&operation);
    fflush(stdin);
    switch (operation)
    {
      case 'a':
        printf("Enter a value: \n");
        scanf("%d",&value);
        status = add_to_end(list,value);
        display_status(status);
        break;

      case 'b':
        printf("Enter a value: \n");
        scanf("%d",&value);
        status = add_to_start(list,value);
        display_status(status);
        break;

      case 'c':
        printf("Enter a value and position: \n");
        scanf("%d %d",&value,&position);
        status = insert_at(list,value,position);
        display_status(status);
        break;

      case 'd':
        printf("Enter a value: \n");
        scanf("%d",&value);
        status = add_unique(list,value);
        display_status(status);
        break;

      case 'e':
        status = remove_from_start(list);
        display_status(status);
        break;

      case 'f':
        status = remove_from_end(list);
        display_status(status);
        break;

      case 'g':
        printf("Enter a position: \n");
        scanf("%d",&position);
        status = remove_at(list,position);
        display_status(status);
        break;

      case 'h':
        printf("Enter a value: \n");
        scanf("%d",&value);
        status = remove_first_occurrence(list,value);
        display_status(status);
        break;

      case 'i':
        printf("Enter a value: \n");
        scanf("%d",&value);
        status = remove_all_occurrences(list,value);
        display_status(status);
        break;
      
      case 'j':
        status = clear_list(list);
        display_status(status);
        break;

      case 'k':
        printf("Enter a value: \n");
        scanf("%d",&value);
        index = search(list,value);
        printf("%s", (index == -1)? "number does not exist": "number exists");
        break;
      
      case 'l':
        display(list);
        break;

      default:
        break;
    }
    printf("\n----------------------------------------------------------\n");
    fflush(stdin);
  }

  return 0;
}