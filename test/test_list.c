#include<stdio.h>
#include "../list.h"


void assertEqual(int expected, int actual, char *message){
  char symbol[] = " ✅  ";
  char error_symbol[] = " ❌  ";
  if(actual == expected){
    printf("%s",symbol);
    printf("%s",message);
    printf("\n");
  }else{
    printf("%s",error_symbol);
    printf("%s\n        ",message);
    printf("Actual: %d   ",actual);
    printf("Expected: %d\n",expected); 
  }
}

void run_test_cases(){
  List_ptr list1 = create_list(); 
  Status status1 = add_to_end(list1 ,5);
  char message1[] = "should add given number in list at end and return 1 on Success";
  assertEqual(1,status1,message1);


  List_ptr list2 = create_list();
  add_to_end(list2,2);
  Status status2 = add_to_start(list2 ,1);
  char message2[] = "should add given number in list at begining and return 1 on Success";
  assertEqual(1,status2,message2);

}

int main(){
  run_test_cases();
  return 0;
}