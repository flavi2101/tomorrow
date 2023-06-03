
    #include <stdio.h>
    
    struct date {
            int year;
            int month;
            int day;
        };
    
    /* function prototypes */
    void printDate(struct date);
    void readDate(struct date *);
    struct date advanceDay(struct date); 
    void checkData(struct date *,int, int);
    void handleLastDayOfMonth(struct date * , struct date, int);
    void correctUserInput (struct date *, int );
    int checkLeapYear (struct date *, int *);
    
    int main(void) {
    	struct date today, tomorrow;
    	readDate(&today);
     	printDate(today);
     	tomorrow = advanceDay(today);
    	printDate(tomorrow);
    	return 0;
    }
    
    void readDate(struct date * inputData){
        const int isDay = 1;
        const int isMonth =0;
        int isLeap;
        int * isLeapPtr = &isLeap;
     
        printf("Inset the Year:\n");
        scanf("%d", &inputData->year);
        
        printf("Insert the Month:\n");
        scanf("%d", &inputData->month);
        
        printf("Insert the Day:\n");
        scanf("%d", &inputData->day);
       
        isLeap = checkLeapYear(inputData, isLeapPtr);
        
        checkData(inputData, isDay, isLeap);
        checkData(inputData, isMonth, isLeap);
    }
    
    int checkLeapYear (struct date *leapYear, int * checkLeapToPassCheckData){
        int aux = *(&leapYear->year);
        
        if (!(aux % 4)){
            * checkLeapToPassCheckData = 1;
        } else if(!(aux % 100)){
            * checkLeapToPassCheckData = 1;
        } else if(!(aux % 400)){
            * checkLeapToPassCheckData = 1;
        } else * checkLeapToPassCheckData = 0;
        return * checkLeapToPassCheckData;
    }
    
    void checkData(struct date *inputValue,int checkIsDayOrMonth, int leapYear){
       int number_day31=31, number_day30 = 30, number_day28 = 28;
       
       if(checkIsDayOrMonth){
           switch(*(&inputValue->month)){
               case 1:  correctUserInput (inputValue,  number_day31);
               break;
               
               case 2:  
                    if (leapYear) correctUserInput (inputValue,  29);
                    else correctUserInput (inputValue,  number_day28);
               break;
               
               case 3:  correctUserInput (inputValue,  number_day31);
               break;
               
               case 4:  correctUserInput (inputValue,  number_day30);
               break;

               case 5:  correctUserInput (inputValue,  number_day31);
               break;
               
               case 6:  correctUserInput (inputValue,  number_day30);
               break;
               
               case 7:  correctUserInput (inputValue,  number_day31);
               break;
               
               case 8:  correctUserInput (inputValue,  number_day31);
               break;
               
               case 9:  correctUserInput (inputValue,  number_day30);
               break;
               
               case 10:  correctUserInput (inputValue,  number_day31);
               break;
               
               case 11:  correctUserInput (inputValue,  number_day31);
               break;
               
               case 12:  correctUserInput (inputValue,  number_day31);
               break;
           }
       
       }else{
           
            while(*(&inputValue->month) > 12){
                printf("invalid month, try again:\n");
                scanf("%d", &inputValue->month);
        
          }
       }
    }
    
    void correctUserInput (struct date * changeInputUser, int dayValue){
         while(*(&changeInputUser->day) > dayValue)
                {
                        printf("invalid Day, try again:\n");
                        scanf("%d", &changeInputUser->day);
                }
    }
    
    void printDate(struct date printuserDate){
        
     printf("%02d/%02d/%d \n", printuserDate.month, printuserDate.day, printuserDate.year);   
        
    }
    
    struct date advanceDay(struct date oldDay){
        struct date newDay;
        struct date * ptrNewDay = &newDay;
        int const number_day31=31, number_day30 = 30,number_day29 = 29;
        
        switch(oldDay.month){
            case 1 :{
               handleLastDayOfMonth(ptrNewDay,oldDay,number_day31);
            } 
            case 2 :{
                int checkYear, * checkYearPtr = &checkYear;
                checkYear = checkLeapYear(&oldDay, checkYearPtr);
                
                if(checkYear) handleLastDayOfMonth(ptrNewDay,oldDay,number_day29);
                else  handleLastDayOfMonth(ptrNewDay,oldDay,28);
               
            } 
            break;
           
            case 3 :{
               handleLastDayOfMonth(ptrNewDay,oldDay,number_day31);
            } 
            break;
             case 4 :{
               handleLastDayOfMonth(ptrNewDay,oldDay,number_day30);
            } 
            break;
            case 5 :{
               handleLastDayOfMonth(ptrNewDay,oldDay,number_day31);
            } 
            break;
             case 6 :{
               handleLastDayOfMonth(ptrNewDay,oldDay,number_day30);
            } 
            break;
            case 7 :{
               handleLastDayOfMonth(ptrNewDay,oldDay,number_day31);
            } 
            break;
            case 8 :{
               handleLastDayOfMonth(ptrNewDay,oldDay,number_day31);
            } 
            break;
             case 9 :{
               handleLastDayOfMonth(ptrNewDay,oldDay,number_day30);
            } 
            break;
            case 10 :{
               handleLastDayOfMonth(ptrNewDay,oldDay,number_day31);
            } 
            break;
             case 11 :{
               handleLastDayOfMonth(ptrNewDay,oldDay,number_day30);
            } 
            break;
              case 12 :{
               handleLastDayOfMonth(ptrNewDay,oldDay,number_day31);
            } 
            break;
            
        }
        
        return newDay;
    }
    
    void handleLastDayOfMonth(struct date * newValuePtr, struct date oldValuesDate, int numberOfDays){
      
       
         if(oldValuesDate.day < numberOfDays){
                    *(&newValuePtr->year) = oldValuesDate.year;
                    *(&newValuePtr->month) = oldValuesDate.month;
                    *(&newValuePtr->day) = oldValuesDate.day +1;
                    
                }else{
                    
                    if( oldValuesDate.month != 12){
                        
                        *(&newValuePtr->year) = oldValuesDate.year;
                        *(&newValuePtr->month) = oldValuesDate.month + 1;
                        *(&newValuePtr->day) = 1;
                  
                    }else{
                        *(&newValuePtr->year) = oldValuesDate.year +1;
                        *(&newValuePtr->month) = 1;
                        *(&newValuePtr->day) = 1;
                    }
                    
                }
    }