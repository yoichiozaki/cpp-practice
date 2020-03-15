#include <bits/stdc++.h>
using namespace std;

struct card {
    char suit, value;
};
using card = struct card;

// bubble sort is stable.
void bubble_sort(card a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j >= i+1; j--) {
            if (a[j].value < a[j-1].value) {
                card t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
            }
        }
    }
}

void selection_sort(card a[], int n) {
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (a[j].value < a[minj].value) {
                minj = j;
            }
        }
        card t = a[i];
        a[i] = a[minj];
        a[minj] = t;
    }
}

void print_cards(card a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << a[i].suit << a[i].value;
    }
    cout << endl;
}

bool is_stable(card c1[], card c2[], int n) {
    for (int i = 0; i < n; i++) {
        if (c1[i].suit != c2[i].suit) {
            return false;
        }
    }
    return true;
}

int main() {
    card c1[100], c2[100];
    int n; char ch;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> c1[i].suit >> c1[i].value;
    for (int i = 0; i < n; i++) c2[i] = c1[i];
    bubble_sort(c1, n);
    selection_sort(c2, n);
    print_cards(c1, n);
    cout << "Stable" << endl;
    print_cards(c2, n);
    cout << (is_stable(c1, c2, n) ? "Stable" : "Not stable") << endl;
    return 0;
}