#include<stdio.h>
#include "../list.h"

void green(){
  printf("\033[1;30m");
}

void red(){
  printf("\033[0;31m");
}

void white(){
  printf("\033[1;0m");
}

void assertEqual(int expected, int actual, char *message){
  char symbol[] = " ✔ ";
  char error_symbol[] = " ✘ ";
  if(actual == expected){
    green();
    printf("   %s %s\n",symbol,message);
  }else{
    red();
    printf("   %s %s\n        Actual: %d   Expected: %d\n",error_symbol, message, actual, expected);
  }
  white();
}

void run_test_cases(){
  printf("add_to_end\n");
  List_ptr list1 = create_list(); 
  char message1[] = "should add given number in list at end and return 1 on Success";
  assertEqual(1,add_to_end(list1 ,5),message1);

  printf("add_to_start\n");
  List_ptr list2 = create_list();
  add_to_end(list2,2);
  char message2[] = "should add given number in list at begining and return 1 on Success";
  assertEqual(0, add_to_start(list2 ,1),message2);

  printf("insert_at\n");
  List_ptr list3 = create_list();
  add_to_end(list3,2);
  add_to_end(list3,4);
  char message3[] = "should insert given number at given position in list and return 1 on Success";
  assertEqual(1,insert_at(list3 ,3 ,1), message3);

  printf("add_unique\n");
  List_ptr list4 = create_list();
  add_to_end(list4,2);
  char message4[] = "should add a unique item on the list at the end return 1 on Success";
  assertEqual(1, add_unique(list4 ,3), message4);

  List_ptr list5 = create_list();
  add_to_end(list5,2);
  char message5[] = "should not add the value in list if it is not unique and return 0";
  assertEqual(0, add_unique(list5 ,2), message5);

  printf("remove_from_start\n");
  List_ptr list6 = create_list();
  add_to_end(list6,2);
  char message6[] = "should remove a number from the beginning of the list and return 1";
  assertEqual(1, remove_from_start(list6), message6);

  List_ptr list7 = create_list();
  char message7[] = "should not remove anything and return 0 if the list is empty";
  assertEqual(0, remove_from_start(list7), message7);

}

int main(){
  run_test_cases();
  return 0;
}