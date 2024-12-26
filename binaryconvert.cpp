#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double base_2_dec(char bin[], const int base);
void dec_2_base(const double &dec, const int base, char outputarr[]);

int main()
{
  int dec;
  cout << "\nInput Base:\n\tBase-";
  cin >> dec;
  int dec2;
  cout << "Output Base:\n\tBase-";
  cin >> dec2;

  char number[100];
  cout << "Enter Number: ";
  cin >> number;
  dec_2_base(base_2_dec(number, dec), dec2, number);
  cout << "Base-" << dec2 << ": " << setprecision(15) << number << endl;
  cout << endl;

  return 0;
}

double base_2_dec(char bin[], const int base)
{
  double output = 0;
  int i = 0;

  while (bin[i] != '\0' && bin[i] != '.')
  {
    if (bin[i] >= 64)
      bin[i] -= 7;
    i++;
  };

  for (int j = 0; j < i; j++)
  {
    output += (bin[j] - 48) * (pow(base, i - j - 1));
  }

  if (bin[i] == '.')
  {

    int j = i + 1;

    while (bin[j] != '\0')
    {
      output += (bin[j] - 48) * pow(base, (j - i) * (-1));
      j++;
    };
  }
  cout << "Base-10: " << output << endl;
  return output;
}

void dec_2_base(const double &dec, const int base, char outputarr[])
{
  int inputWhole = static_cast<int>(dec);
  double inputDeci = 0;
  int counter = 0;

  char temp;

  if (dec - inputWhole > 0)
    inputDeci = dec - static_cast<double>(inputWhole);

  while (inputWhole != 0)
  {
    // output+=inputWhole%base*pow (10,counter);
    // outputarr[counter] = inputWhole%base+48;

    if (inputWhole % base > 9)
      outputarr[counter] = static_cast<char>(inputWhole % base + 55);
    else
      outputarr[counter] = inputWhole % base + 48;
    inputWhole /= base;
    counter++;
  };

  outputarr[counter] = '\0';
  for (int i = 0; i < (counter / 2); i++)
  {
    temp = outputarr[i];
    outputarr[i] = outputarr[counter - i - 1];
    outputarr[counter - i - 1] = temp;
  }

  if (inputDeci != 0)
  {
    outputarr[counter] = '.';
    counter++;
  }

  while (inputDeci != 0)
  {
    // output+=static_cast<double>(static_cast<int>((base*inputDeci))/1*pow(10,counter));
    outputarr[counter] = static_cast<int>((base * inputDeci)) / 1;
    if (outputarr[counter] > 9)
      outputarr[counter] += 55;
    else
      outputarr[counter] += 48;
    inputDeci = (base * inputDeci) - static_cast<int>((base * inputDeci)) / 1;
    counter++;
  };
}