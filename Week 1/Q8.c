#include <stdio.h>
#include <string.h>

#define SUBJECTS 5

struct Student {
    int roll;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float percentage;
    char grade;
    int failed;
};

char calculateGrade(float percentage) {
    if (percentage >= 90)
        return 'A';
    else if (percentage >= 80)
        return 'B';
    else if (percentage >= 70)
        return 'C';
    else if (percentage >= 60)
        return 'D';
    else if (percentage >= 50)
        return 'E';
    else
        return 'F';
}

int main() {
    struct Student s[100];
    int n, i, j;
    int topper = 0;
    float classTotal = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);

        printf("Enter name: ");
        scanf(" %[^\n]", s[i].name);

        s[i].total = 0;
        s[i].failed = 0;

        printf("Enter marks in 5 subjects:\n");

        for (j = 0; j < SUBJECTS; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &s[i].marks[j]);

            s[i].total += s[i].marks[j];

            if (s[i].marks[j] < 40)
                s[i].failed = 1;
        }

        s[i].percentage = s[i].total / SUBJECTS;
        s[i].grade = calculateGrade(s[i].percentage);

        classTotal += s[i].percentage;

        if (s[i].percentage > s[topper].percentage)
            topper = i;
    }

    printf("\n========== STUDENT RESULTS ==========\n");

    for (i = 0; i < n; i++) {
        printf("\nRoll Number : %d", s[i].roll);
        printf("\nName        : %s", s[i].name);
        printf("\nTotal       : %.2f", s[i].total);
        printf("\nPercentage  : %.2f%%", s[i].percentage);
        printf("\nGrade       : %c\n", s[i].grade);
    }

    printf("\n========== CLASS TOPPER ==========\n");
    printf("Roll Number: %d\n", s[topper].roll);
    printf("Name       : %s\n", s[topper].name);
    printf("Percentage : %.2f%%\n", s[topper].percentage);

    printf("\n========== FAILED STUDENTS ==========\n");

    for (i = 0; i < n; i++) {
        if (s[i].failed) {
            printf("Roll Number: %d, Name: %s\n",
                   s[i].roll, s[i].name);
        }
    }

    printf("\nClass Average = %.2f%%\n", classTotal / n);

    return 0;
}
