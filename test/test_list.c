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

void print_result(int passed,char *message){
  if(passed){
    green();
    printf("   ✔ %s\n",message);
  }else{
    red();
    printf("   ✘ %s\n",message);
  }
  white();
}

void test_add_to_end(){
  printf("\nadd_to_end\n");
  List_ptr list = create_list();
  Status status = add_to_end(list,2);
  char message[] = "should add given number in list at end, increment count and return 1";
  int passed = status == 1 && list->count == 1 && list->last->value == 2;
  print_result(passed,message);
}

void test_add_to_start(){
  printf("\nadd_to_start\n");
  List_ptr list = create_list();
  Status status = add_to_start(list,2);
  char message[] = "should add given number in list at begining, increment count and return 1";
  int passed = status == 1 && list->count == 1 && list->head->value == 2;
  print_result(passed,message);
  destroy_list(list);
}

void test_insert_at(){
  printf("\ninsert_at\n");
  List_ptr list = create_list();
  add_to_end(list,2);
  add_to_end(list,3);
  add_to_end(list,6);
  Status status = insert_at(list,4,2 );
  char message[] = "should insert given number at given position in list and return 1";
  int passed = status == 1 && list->count == 4 && is_num_on_position(list,4,2)==1;
  print_result(passed,message);
  destroy_list(list);
}

void test_search(){
  printf("\nsearch\n");
  List_ptr list = create_list();
  add_to_end(list,2);
  add_to_end(list,3);
  add_to_end(list,4);
  int status = search(list, 3);
  char message[] = "should return the index of element if exists";
  int passed = status == 1;
  print_result(passed,message);

  char message2[] = "should return the -1 if element does not exists";
  int status2 = search(list,99);
  int passed2 = status2 == -1;
  print_result(passed2,message2);
  destroy_list(list);
}

void test_add_unique(){
  printf("\nadd_unique\n");
  List_ptr list = create_list();
  add_to_end(list,2);
  Status status = add_unique(list,99);
  char message[] = "should add a unique item on the list at the end";
  int passed = status == 1 && list->count == 2 && list->last->value == 99;
  print_result(passed,message);

  Status status2 = add_unique(list,2);
  char message2[] = "should not add item if it is not unique";
  int passed2 = status2 == 0 && list->count == 2;
  print_result(passed2,message2);
  destroy_list(list);
}

void test_remove_from_start(){
  printf("\nremove_from_start\n");
  List_ptr list = create_list();
  add_to_end(list,1);
  add_to_end(list,2);
  Status status = remove_from_start(list);
  char message[] = "should remove a number from the beginning of the list";
  int passed = status == 1 && list->count == 1 && list->head->value == 2;
  print_result(passed,message);
  destroy_list(list);

  List_ptr list2 = create_list();
  Status status2 = remove_from_start(list2);
  char message2[] = "should not remove a number from the beginning of the list";
  int passed2 = status2 == 0 && list->count == 0 && list->head==NULL;
  print_result(passed2,message2);
  destroy_list(list2);
} 

void test_remove_from_end(){
  printf("\nremove_from_end\n");
  List_ptr list = create_list();
  add_to_end(list,1);
  add_to_end(list,2);
  Status status = remove_from_end(list);
  char message[] = "should remove a number from the end of the list";
  int passed = status == 1 && list->count == 1 && list->last->value == 1;
  print_result(passed,message);
  destroy_list(list);

  List_ptr list2 = create_list();
  Status status2 = remove_from_end(list2);
  char message2[] = "should not remove a number from the end of the list";
  int passed2 = status2 == 0 && list->count == 0 && list->last==NULL;
  print_result(passed2,message2);
  destroy_list(list2);
} 

void test_remove_at(){
  printf("\nremove_at\n");
  List_ptr list = create_list();
  add_to_end(list,1);
  add_to_end(list,2);
  Status status = remove_at(list,1);
  char message[] = "should remove a number from given position in list";
  int passed = status == 1 && list->count == 1;
  print_result(passed,message);
  destroy_list(list);

  List_ptr list2 = create_list();
  int count = list->count;
  Status status2 = remove_at(list2,99);
  char message2[] = "should not remove if position is invalid";
  int passed2 = status2 == 0 && count == list->count;
  print_result(passed2,message2);
  destroy_list(list2);
} 

void test_remove_first_occurrence(){
  printf("\nremove_first_occurrence\n");
  List_ptr list = create_list();
  add_to_end(list,1);
  add_to_end(list,1);
  add_to_end(list,2);
  int count = list->count;
  Status status = remove_first_occurrence(list,1);
  char message[] = "should remove a first occurrence of given number from list";
  int passed = status == 1 && list->count == count - 1;
  print_result(passed,message);
  destroy_list(list);

  List_ptr list2 = create_list();
  int count2 = list->count;
  Status status2 = remove_first_occurrence(list2,99);
  char message2[] = "should not remove if number does not exists";
  int passed2 = status2 == 0 && count2 == list->count;
  print_result(passed2,message2);
  destroy_list(list2);
} 

void test_remove_all_occurrences(){
  printf("\nremove_all_occurrences\n");
  List_ptr list = create_list();
  add_to_end(list,1);
  add_to_end(list,1);
  add_to_end(list,2);
  int count = list->count;
  Status status = remove_all_occurrences(list,1);
  char message[] = "should remove all occurrence of given number from list";
  int passed = status == 1 && list->count == count - 2 && search(list,1) == -1;
  print_result(passed,message);
  destroy_list(list);

  List_ptr list2 = create_list();
  int count2 = list->count;
  Status status2 = remove_all_occurrences(list2,99);
  char message2[] = "should not remove if number does not exists";
  int passed2 = status2 == 0 && count2 == list->count;
  print_result(passed2,message2);
  destroy_list(list2);
} 

void test_clear_list(){
  printf("\nclear_list\n");
  List_ptr list = create_list();
  add_to_end(list,1);
  add_to_end(list,2);
  Status status = clear_list(list);
  char message[] = "should clear whole list";
  int passed = status == 1 && list->count == 0 && list->head == NULL && list->last == NULL;
  print_result(passed,message);
  destroy_list(list);
}

void test_is_num_on_position(){
  printf("\nis_num_on_position\n");
  List_ptr list = create_list();
  add_to_end(list,1);
  int status = is_num_on_position(list,1,0);
  char message[] = "should return 1 if given num is on the given position in list";
  print_result(status == 1, message);
  destroy_list(list);

  List_ptr list2 = create_list();
  int status2 = is_num_on_position(list2,1,0);
  char message2[] = "should return 0 if given num is not on the given position in list";
  print_result(status2 == 0, message2);
  destroy_list(list2);
}

int main(){
  test_add_to_end();
  test_add_to_start();
  test_insert_at();
  test_search();
  test_add_unique();
  test_remove_from_start();
  test_remove_from_end();
  test_remove_at();
  test_remove_first_occurrence();
  test_remove_all_occurrences();
  test_clear_list();
  test_is_num_on_position();
  return 0;
}