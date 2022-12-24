#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<string> &v1, vector<string> &v2)
{
    int id1 = stoi(v1[1]), id2 = stoi(v2[1]);
    int offset1 = stoi(v1[2]), offset2 = stoi(v2[2]);
    if (id1 != id2)
    {
        return id1 < id2;
    }
    return offset1 < offset2;
}
int main()
{

    ifstream source;
    source.open("text.txt");
    vector<vector<string>> matrix;
    string line;
    while (getline(source, line))
    {
        vector<string> add;
        stringstream split(line);
        string word;
        while (split >> word)
        {
            add.push_back(word);
        }
        matrix.push_back(add);
    }

    sort(matrix.begin(), matrix.end(), cmp);

    for (int i = 0; i < matrix.size();)
    {
        string top = matrix[i][1];
        if (((i + 1) < matrix.size()) && matrix[i][0] == matrix[i + 1][0] && matrix[i][1] == matrix[i + 1][1] && matrix[i][2] == matrix[i + 1][2] && matrix[i][3] == matrix[i + 1][3] && matrix[i][4] == matrix[i + 1][4])
        {
            cout << matrix[i][0] << " " << top << " Duplicate  matrix" << endl;
            while (i < matrix.size() && matrix[i][1] == top)
            {
                i++;
            }
            continue;
        }
        if (matrix[i][2] != "0")
        {
            cout << matrix[i][0] << " " << top << " Missing  matrix" << endl;
            while (i < matrix.size() && matrix[i][1] == top)
            {
                i++;
            }
            continue;
        }
        if (matrix[i][2] == "0" && matrix[i][3] == "0")
        {
            cout << matrix[i][0] << " " << top << " " << stoi(matrix[i][4]) + 20 << endl;
            i++;
            continue;
        }
        int l_o_d = stoi(matrix[i][4]);
        bool check = false;
        i++;
        while ((i + 1) < matrix.size() && top == matrix[i][1])
        {
            if (matrix[i][3] == "1")
            {
                int offset = stoi(matrix[i][2]) * 8;
                if (l_o_d != offset)
                {
                    check = true;
                    cout << matrix[i][0] << " " << top << " Mismatch  matrix" << endl;
                }
                l_o_d += stoi(matrix[i][4]);
            }
            else
            {
                l_o_d += stoi(matrix[i][4]);
                check = true;
                cout << matrix[i][0] << " " << top << " " << l_o_d + 20 << endl;
            }
            i++;
        }
        if (check == false)
        {
            cout << matrix[i][0] << " " << matrix[i][1] << " Missing  matrix" << endl;
        }
    }

    return 0;
}