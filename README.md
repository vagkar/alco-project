# Project στο μάθημα Αλγόριθμοι και Πολυπλοκότητα

## Περιγραφή του προβλήματος χρωματισμού κορυφών

   Το πρόβλημα χρωματισμού γραφήματος είναι ένα NP-Hard πρόβλημα το οποίο έχει ως σκοπό το χρωματισμό κορυφών με διαφορετικά χρώματα απο τις γειτονικές κορυφές τους και ταυτόχρονα τη χρήση του ελάχιστου δυνατού πλήθους χρωμάτων. Στην υλοποίηση του Project θα χρησιμοποιηθούν ο First Fit ο οποίος ανήκει στους άπληστους αλγορίθμους και χρωματίζει τις κορυφές με το πρώτο διαθέσιμο χρώμα και ο DSatur όπου χρωματίζει την κορυφή με το μεγαλύτερο βαθμό κορεσμού. Και οι δύο αλγόριθμοι που χρησιμοποιούνται είναι βέλτιστοι.

---

## Πηγαίος Κώδικας

   - Όλα τα πηγαία αρχεία της εφασρμογής βρίσκονται στο φάκελο [src](https://github.com/vagkar/alco-project/tree/main/app/src)

   - Υλοποίηση του [First Fit](https://github.com/vagkar/alco-project/blob/main/app/src/Graph.cpp#L115)

   - Υλοποίηση του [DSatur](https://github.com/vagkar/alco-project/blob/main/app/src/Graph.cpp#L167)

---

## Οδηγίες Εγκατάστασης

   - Εγκατάσταση του Version Control [Git](https://git-scm.com/downloads)
   
   - Εγκατάσταση του Compiler [TDM-GCC MinGW](https://jmeubank.github.io/tdm-gcc/)
   
   - Εγκατάσταση του Visual Studio Code [VS Code](https://code.visualstudio.com/download)

   - Extension για το Visual Studio Code: C/C++ της Microsoft

---

## Οδηγίες Εκτέλεσης

   ### Δημιουργία τοπικού repository

   1. Ανοίγουμε το git-bash.exe
   
   2. Εάν επιθυμούμε να γίνει η δημιουργία σε συγκεκριμένο φάκελο,
Εκτελούμε την εντολή `cd "διαδρομή φακέλου"`
   
   3. Στη συνέχεια εκτελούμε την εντολή `git clone https://github.com/vagkar/alco-project.git`
   
   ### Εκτέλεση του Project
   
   1. Ανοίγουμε ένα τερματικό είτε μέσω του vscode είτε ένα command.exe
   
   2. Πηγαίνουμε στο φάκελο app\src του repository
   
   3. Για το compile και τη δημιουργία εκτελέσιμου αρχείου,
Εκτελούμε την εντολή `g++ main.cpp Graph.cpp Vertex.cpp -o main -std=c++17 -Wall -Wextra`
   
   4. Για να εκτελέσουμε το αρχείο που δημιουργήσαμε χρησιμοποιούμε την εντολή 
   `main` σε Windows 
   `./main` σε Unix

---

[Site of Project](https://vagkar.github.io/alco-project/ "Project page")
