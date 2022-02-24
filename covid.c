#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct Point
{
    int covid;
    int Breathing_Problem,Fever,Dry_Cough,Sore_throat,Running_nose,Asthma,Chronic_Lung_Disease,Headache,Heart_Disease,Diabetes,Hyper_Tension,Fatigue,Gastrointestinal,Abroad_travel,Contact_with_COVID_Patient,Attended_Large_Gathering,Visited_Public_Exposed_Places,Family_working_in_Public_Exposed_Places,Wearing_Masks,Sanitization_from_Market;
    double distance;
}point_t;

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");tok && *tok; tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}


char* classifyAPoint(point_t arr[], int n, int k, point_t p)
{
    for (int i = 1; i < n; i++)
        arr[i].distance = sqrt((arr[i].Breathing_Problem - p.Breathing_Problem) * (arr[i].Breathing_Problem - p.Breathing_Problem)
                                 +(arr[i].Fever - p.Fever) * (arr[i].Fever - p.Fever) 
                                 +(arr[i].Dry_Cough - p.Dry_Cough) * (arr[i].Dry_Cough - p.Dry_Cough) 
                                 +(arr[i].Sore_throat - p.Sore_throat) * (arr[i].Sore_throat - p.Sore_throat) 
                                 +(arr[i].Running_nose - p.Running_nose) * (arr[i].Running_nose - p.Running_nose) 
                                 +(arr[i].Asthma - p.Asthma) * (arr[i].Asthma - p.Asthma) 
                                 +(arr[i].Chronic_Lung_Disease - p.Chronic_Lung_Disease) * (arr[i].Chronic_Lung_Disease - p.Chronic_Lung_Disease) 
                                 +(arr[i].Headache - p.Headache) * (arr[i].Headache - p.Headache) 
                                 +(arr[i].Heart_Disease - p.Heart_Disease) * (arr[i].Heart_Disease - p.Heart_Disease) 
                                 +(arr[i].Diabetes - p.Diabetes) * (arr[i].Diabetes - p.Diabetes) 
                                 +(arr[i].Hyper_Tension - p.Hyper_Tension) * (arr[i].Hyper_Tension - p.Hyper_Tension) 
                                 +(arr[i].Fatigue - p.Fatigue) * (arr[i].Fatigue - p.Fatigue) 
                                 +(arr[i].Gastrointestinal - p.Gastrointestinal) * (arr[i].Gastrointestinal - p.Gastrointestinal) 
                                 +(arr[i].Abroad_travel - p.Abroad_travel) * (arr[i].Abroad_travel - p.Abroad_travel) 
                                 +(arr[i].Contact_with_COVID_Patient - p.Contact_with_COVID_Patient) * (arr[i].Contact_with_COVID_Patient - p.Contact_with_COVID_Patient) 
                                 +(arr[i].Attended_Large_Gathering - p.Attended_Large_Gathering) * (arr[i].Attended_Large_Gathering - p.Attended_Large_Gathering) 
                                 +(arr[i].Visited_Public_Exposed_Places - p.Visited_Public_Exposed_Places) * (arr[i].Visited_Public_Exposed_Places - p.Visited_Public_Exposed_Places) 
                                 +(arr[i].Wearing_Masks - p.Wearing_Masks) * (arr[i].Wearing_Masks - p.Wearing_Masks) 
                                 +(arr[i].Sanitization_from_Market - p.Sanitization_from_Market) * (arr[i].Sanitization_from_Market - p.Sanitization_from_Market) 
                                 +(arr[i].Family_working_in_Public_Exposed_Places - p.Family_working_in_Public_Exposed_Places) * (arr[i].Family_working_in_Public_Exposed_Places - p.Family_working_in_Public_Exposed_Places));

    point_t temp;
    for (int i = 1; i < n; i++)
        for (int j = i+1; j < n; j++) {
            if (arr[i].distance > arr[j].distance) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

    /*for(int i=1; i<n; i++)
    {
        printf("%d , %d , %d , %d , %d , %d , %d , %d , %d , %d , %d , %d , %d , %d , %d , %d , %d , %d , %d , %d , %d , %lf\n",arr[i].covid, arr[i].Breathing_Problem ,arr[i].Fever ,arr[i].Dry_Cough ,arr[i].Sore_throat ,arr[i].Running_nose ,arr[i].Asthma ,arr[i].Chronic_Lung_Disease ,arr[i].Headache ,arr[i].Heart_Disease ,arr[i].Diabetes ,arr[i].Hyper_Tension ,arr[i].Fatigue ,arr[i].Gastrointestinal ,arr[i].Abroad_travel ,arr[i].Contact_with_COVID_Patient ,arr[i].Attended_Large_Gathering ,arr[i].Visited_Public_Exposed_Places ,arr[i].Family_working_in_Public_Exposed_Places ,arr[i].Wearing_Masks ,arr[i].Sanitization_from_Market, arr[i].distance);
    }*/
 
    int freq1 = 0;
    int freq2 = 0;
    
    for (int i = 1; i < k+1; i++)
    {
        if (arr[i].covid==0)
            freq1++;
        else if (arr[i].covid==1)
            freq2++;
    }
    if (freq1 > freq2){
        return "negatif";
    }else{
        return "positif";
    }
}

int main()
{
    FILE* stream = fopen("Covid_Dataset.csv", "r");
    point_t arr[5500];
    int n=0;
    char line[5500];
    while (fgets(line, 5500, stream))
    {
        arr[n].Breathing_Problem = atoi(getfield(strdup(line), 1));
        arr[n].Fever = atoi(getfield(strdup(line), 2));
        arr[n].Dry_Cough = atoi(getfield(strdup(line), 3));
        arr[n].Sore_throat = atoi(getfield(strdup(line), 4));
        arr[n].Running_nose = atoi(getfield(strdup(line), 5));
        arr[n].Asthma = atoi(getfield(strdup(line), 6));
        arr[n].Chronic_Lung_Disease = atoi(getfield(strdup(line), 7));
        arr[n].Headache = atoi(getfield(strdup(line), 8));
        arr[n].Heart_Disease = atoi(getfield(strdup(line), 9));
        arr[n].Diabetes = atoi(getfield(strdup(line), 10));
        arr[n].Hyper_Tension = atoi(getfield(strdup(line), 11));
        arr[n].Fatigue = atoi(getfield(strdup(line), 12));
        arr[n].Gastrointestinal = atoi(getfield(strdup(line), 13));
        arr[n].Abroad_travel = atoi(getfield(strdup(line), 14));
        arr[n].Contact_with_COVID_Patient = atoi(getfield(strdup(line), 15));
        arr[n].Attended_Large_Gathering = atoi(getfield(strdup(line), 16));
        arr[n].Visited_Public_Exposed_Places = atoi(getfield(strdup(line), 17));
        arr[n].Family_working_in_Public_Exposed_Places = atoi(getfield(strdup(line), 18));
        arr[n].Wearing_Masks = atoi(getfield(strdup(line), 19));
        arr[n].Sanitization_from_Market = atoi(getfield(strdup(line), 20));
        arr[n].covid = atoi(getfield(strdup(line), 21));
        n++;
    }
    FILE *fp = fopen("data.tmp", "w");

    for(int i=1; i<n; i++)
    {
    fprintf(fp,"%d %d %d\n",arr[i].Breathing_Problem +arr[i].Fever +arr[i].Dry_Cough +arr[i].Sore_throat +arr[i].Running_nose +arr[i].Asthma +arr[i].Chronic_Lung_Disease +arr[i].Headache +arr[i].Heart_Disease +arr[i].Diabetes +arr[i].Hyper_Tension ,arr[i].Fatigue +arr[i].Gastrointestinal +arr[i].Abroad_travel +arr[i].Contact_with_COVID_Patient +arr[i].Attended_Large_Gathering +arr[i].Visited_Public_Exposed_Places +arr[i].Family_working_in_Public_Exposed_Places +arr[i].Wearing_Masks +arr[i].Sanitization_from_Market , arr[i].covid);
    }

    
    FILE *gnupipe = NULL;
    char *GnuCommands [] = {"set palette model RGB define(0 'red', 1 'green', 2 'black')", "set xrange[-2:12]", "set yrange[-2:12]", "set title \"Demo\"", "plot 'data.tmp' with point pointtype 7 palette"};
    gnupipe = _popen("gnuplot -persitent", "w");
    for (int i =0;i<5;i++){
        fprintf(gnupipe,"%s\n",GnuCommands[i]);
    }

    point_t p;
    printf("Answer '1' with Yes and '0' with No\n");
    printf("To start press Any Key ....\n");  
    getchar(); 

    do{
        printf("Do you have difficulty breathing?\n");
        scanf("%d",&p.Breathing_Problem);
    }while(p.Breathing_Problem != 0 && p.Breathing_Problem != 1);
    do{
        printf("Do you have a fever?\n");
        scanf("%d",&p.Fever);
    }while(p.Fever != 0 && p.Fever != 1);
    do{
        printf("Do you suffer from a dry cough?\n");
        scanf("%d",&p.Dry_Cough);
    }while(p.Dry_Cough != 0 && p.Dry_Cough != 1);
    do{
        printf("Do you have a sore throat?\n");
        scanf("%d",&p.Sore_throat);
    }while(p.Sore_throat != 0 && p.Sore_throat != 1);
    do{
        printf("do you have a Running Nose?\n");
        scanf("%d",&p.Running_nose);
    }while(p.Running_nose != 0 && p.Running_nose != 1);
    do{
        printf("Do you suffer from asthma?\n");
        scanf("%d",&p.Asthma);
    }while(p.Asthma != 0 && p.Asthma != 1);
    do{
        printf("Do you have a chronic lung disease?\n");
        scanf("%d",&p.Chronic_Lung_Disease);
    }while(p.Chronic_Lung_Disease != 0 && p.Chronic_Lung_Disease != 1);
    do{
        printf("Do you have a headache?\n");
        scanf("%d",&p.Headache);
    }while(p.Headache != 0 && p.Headache != 1);
    do{
        printf("Do you suffer from heart disease?\n");
        scanf("%d",&p.Heart_Disease);
    }while(p.Heart_Disease != 0 && p.Heart_Disease != 1);
    do{
        printf("Do you have diabetes?\n");
        scanf("%d",&p.Diabetes);
    }while(p.Diabetes != 0 && p.Diabetes != 1);
    do{
        printf("Do you suffer from hypertension?\n");
        scanf("%d",&p.Hyper_Tension);
    }while(p.Hyper_Tension != 0 && p.Hyper_Tension != 1);
    do{
        printf("Do you feel fatigue?\n");
        scanf("%d",&p.Fatigue);
    }while(p.Fatigue != 0 && p.Fatigue != 1);
    do{
        printf("Do you suffer from gastrointestinal diseases?\n");
        scanf("%d",&p.Gastrointestinal);
    }while(p.Gastrointestinal != 0 && p.Gastrointestinal != 1);
    do{
        printf("Do you travel abroad?\n");
        scanf("%d",&p.Abroad_travel);
    }while(p.Abroad_travel != 0 && p.Abroad_travel != 1);
    do{
        printf("Have you had contact with a COVID patient?\n");
        scanf("%d",&p.Contact_with_COVID_Patient);
    }while(p.Contact_with_COVID_Patient != 0 && p.Contact_with_COVID_Patient != 1);
    do{
        printf("Did you attend a large gathering?\n");
        scanf("%d",&p.Attended_Large_Gathering);
    }while(p.Attended_Large_Gathering != 0 && p.Attended_Large_Gathering != 1);
    do{
        printf("Have you visited outdoor public places?\n");
        scanf("%d",&p.Visited_Public_Exposed_Places);
    }while(p.Visited_Public_Exposed_Places != 0 && p.Visited_Public_Exposed_Places != 1);
    do{
        printf("Does your family work in open public spaces?\n");
        scanf("%d",&p.Family_working_in_Public_Exposed_Places);
    }while(p.Family_working_in_Public_Exposed_Places != 0 && p.Family_working_in_Public_Exposed_Places != 1);
    do{
        printf("Do you wear masks?\n");
        scanf("%d",&p.Wearing_Masks);
    }while(p.Wearing_Masks != 0 && p.Wearing_Masks != 1);
    do{
        printf("Are you cleaning from the market?\n");
        scanf("%d",&p.Sanitization_from_Market);
    }while(p.Sanitization_from_Market != 0 && p.Sanitization_from_Market != 1);
    

    fprintf(fp,"%d %d %d\n",p.Breathing_Problem +p.Fever +p.Dry_Cough +p.Sore_throat +p.Running_nose +p.Asthma +p.Chronic_Lung_Disease +p.Headache +p.Heart_Disease +p.Diabetes +p.Hyper_Tension ,p.Fatigue +p.Gastrointestinal +p.Abroad_travel +p.Contact_with_COVID_Patient +p.Attended_Large_Gathering +p.Visited_Public_Exposed_Places +p.Family_working_in_Public_Exposed_Places +p.Wearing_Masks +p.Sanitization_from_Market , 2);
    
    int k = 3;
    printf ("The value classified is %s.\n", classifyAPoint(arr, n, k, p));
    printf("your point is the black one");
    return 0;
}
