# Project στο μάθημα Αλγόριθμοι και Πολυπλοκότητα

   Το πρόβλημα χρωματισμού γραφήματος τυπικά ορίζεται ως εξής. Δεδομένου ενός μη κατευ‐  
   θυνόμενου απλού γραφήματος G = (V, E) με ένα σύνολο κορυφών V και ένα σύνολο ακμών  
   E, ζητείται η ανάθεση σε κάθε κορυφή v ∈ V ενός ακεραίου c(v) ∈ {1, 2, ..., k} έτσι ώστε το k  
   να ελαχιστοποιείται και να ισχύει ότι c(v) ≠ c(u) ∀{v, u} ∈ E.  

---

## Οδηγίες Εγκατάστασης

   - Εγκατάσταση του Version Control [Git](https://git-scm.com/downloads)
   
   - Εγκατάσταση του Compiler [TDM-GCC MinGW](https://jmeubank.github.io/tdm-gcc/)
   
   - Εγκατάσταση του Visual Studio Code [VS Code](https://code.visualstudio.com/download)

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
