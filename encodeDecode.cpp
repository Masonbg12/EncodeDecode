#include <iostream>
#include <string>

using namespace std;

int main()
{
    string temp = "";

    cout << "Enter message to encode: ";
    getline(cin, temp);
    char message[temp.length()];
    int key[3][3] =   {{1, 2, 3},
                      {9, -1, 2},
                      {8, 3, 4}};
    int keyInverse[3][3] = {0};
    string choice = "";

    for(int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            keyInverse[r][c] = key[r][c];
        }
    }

    int determinant = 0;

    //finding determinant
	for(int i = 0; i < 3; i++)
		determinant = determinant + (keyInverse[0][i] * (keyInverse[1][(i+1)%3] * keyInverse[2][(i+2)%3] - keyInverse[1][(i+2)%3] * keyInverse[2][(i+1)%3]));

	cout<<"\n\ndeterminant: "<<determinant;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++)
			//cout<<((keyInverse[(j+1)%3][(i+1)%3] * keyInverse[(j+2)%3][(i+2)%3]) - (keyInverse[(j+1)%3][(i+2)%3] * keyInverse[(j+2)%3][(i+1)%3]))/ determinant<<"\t";

		cout<<"\n";

    for (int x = 0; x < sizeof(message); x++)
    {
        message[x] = temp[x];
    }

    cout << "encoded message: ";
    for (int x = 0; x < sizeof(message); x++)
    {
        cout << rand() % 100 << " ";
    }

    cout << "\ndecode message: ";
    for (int x = 0; x < sizeof(message); x++)
        cout << message[x];

    cout << "\n";

    cout << "\nMessage recieved, would you like to decode?";
    cin >> choice;

    cout << "\nMessage: Please don't message me again.";

    return 0;
}
}
