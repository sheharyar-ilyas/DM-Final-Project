#include <iostream>
#include <limits>
#include <string>
using namespace std;
int domain[1000];
int codomain[1000];
int image[1000];
int n = 0; 
int m = 0;    
bool functionEntered = false;
bool inputFunction(){
cout<<"Enter number of domain elements: ";
cin>>n;
for(int i = 0; i < n; i++){
cout<<"Domain element " <<i+1<< ": ";
cin>>domain[i];
}
cout<<"Enter number of codomain elements: ";
cin>>m;
for(int i = 0; i < m; i++){
cout<<"Codomain element " << i + 1 << ": ";
cin>>codomain[i];
}
cout<<"Enter function values f(x):" << endl;
for(int i = 0; i < n; i++) {
int value;
bool valid;
do{
valid = false;
cout<<"f(" << domain[i] << ") = ";
cin>>value;
for(int j = 0; j < m; j++) {
if(value == codomain[j]){
valid = true;
break;
}
}
if(!valid){
cout<<"Value not in codomain. Enter again." << endl;
}
} while (!valid);
image[i] = value;
}
// Check real function
for (int i = 0; i<n; i++) {
for (int j = i + 1; j<n; j++) {
if (domain[i] == domain[j] && image[i] != image[j]) {
cout << "This is not a real function." << endl;
return false;
}
}
}
cout<< "Real function entered successfully."<< endl;
return true;
}
// DISPLAY FUNCTION
void displayFunction(){
cout<<"Function in set notation:"<< endl;
cout<< "f = { ";
for(int i = 0; i<n; i++){
cout<< "("<< domain[i] << ", " <<image[i]<< ") ";
}
cout<< "}"<<endl;
}
// VISULA MAPPING 
void visualizeMapping(){
cout << "Step by step mapping:" << endl;
for (int i = 0; i < n; i++){
cout << domain[i] << " maps to "<<image[i]<<endl;
}
}
// ANALYZIE THE FUNCTION
void analyzeFunction(){
bool isInjective = true;
bool isSurjective = true;
// Injective check
for(int i = 0; i<n; i++){
for(int j = i + 1; j<n; j++){
if(image[i] == image[j]){
isInjective = false;
}
}
}
// Surjective check
for(int i = 0; i < m; i++){
bool found = false;
for (int j = 0; j<n; j++){
if (codomain[i] == image[j]){
found = true;
break;
}
}
if(!found){
isSurjective = false;
}
}
cout<<"Function analysis result:"<<endl;
if(isInjective)
cout<<"Function is injective."<<endl;
else
cout<<"Function is not injective."<<endl;
if(isSurjective)
cout<<"Function is surjective."<<endl;
else
cout<<"Function is not surjective."<<endl;
if (isInjective && isSurjective)
cout<<"Function is bijective."<<endl;
else
cout<<"Function is not bijective."<<endl;
}
// INVERSE FUNCTION
void computeInverseFunction(){
bool isInjective = true;
bool isSurjective = true;
// Check Injective
for(int i = 0; i < n; i++){
for(int j = i + 1; j < n; j++){
if(image[i] == image[j]){
isInjective = false;
}
}
if(!isInjective)
break;
}
 // Check Surjective
for(int i = 0; i < m; i++){
bool found = false;
for(int j = 0; j < n; j++){
if(codomain[i] == image[j]){
found = true;
break;
}
}
if(!found){
isSurjective = false;
break;
}
}
// Only compute inverse if bijective
if(isInjective && isSurjective){
cout<<"Inverse function:" << endl;
for(int i = 0; i < n; i++){
cout<<"f inverse of " << image[i] << " is " << domain[i] << endl;
}
}else{
cout << "Inverse function does not exist (function is not bijective)." << endl;
}
}
// compute function
void computeFunction(){
int x;
cout<<"Enter value to compute f(x): ";
cin>>x;
for(int i = 0; i<n; i++){
 if(domain[i] == x){
cout << "f(" << x << ") = "<<image[i]<<endl;
return;
}
}
cout<<"Input not in domain."<<endl;
}
// encrypt Messeges
string encryptMessage(string message, int key){
string result = "";
for (int i = 0; i < message.length(); i++){
char c = message[i];
if (c >= 'A' && c <= 'Z')
result += char((c - 'A' + key) % 26 + 'A');
else if (c >= 'a' && c <= 'z')
result += char((c - 'a' + key) % 26 + 'a');
else
result += c;
}
return result;
}
string decryptMessage(string message, int key){
string result = "";
for (int i = 0; i < message.length(); i++){
char c = message[i];
if (c >= 'A' && c <= 'Z')
result += char((c - 'A' - key + 26) % 26 + 'A');
else if (c >= 'a' && c <= 'z')
result += char((c - 'a' - key + 26) % 26 + 'a');
else
result += c;
}
return result;
}
int main(){
string username, password;
while(true){
cout<<"Enter Username: ";
getline(cin, username);
cout << "Enter Password: ";
getline(cin, password);
if (username == "Admin" && password == "100151"){
cout<<"Login successful."<<endl;
break;
}else{
cout<<"Invalid username or password."<<endl;
}
}
int choice;
do{
cout<<"=========================================================" << endl;
cout << 		"FUNCTION ANALYSIS SYSTEM" << endl;
cout<<"=========================================================" << endl;
cout<<"1. Input Function"<<endl;
cout<<"2. Analyze Function"<<endl;
cout<<"3. Compute Inverse Function"<<endl;
cout<<"4. Compute Function Value"<<endl;
cout<<"5. Encrypt Message"<<endl;
cout<<"6. Decrypt Message"<<endl;
cout<<"7. Exit"<<endl;
cout<<"Enter choice: ";
cin>>choice;
switch (choice) {
case 1:
 functionEntered = inputFunction();
if(functionEntered){
displayFunction();
visualizeMapping();
}
break;
case 2:
if(functionEntered)
analyzeFunction();
else
cout<<"No function entered yet." << endl;
break;
case 3:
if(functionEntered)
computeInverseFunction();
else
cout << "No function entered yet." << endl;
break;
case 4:
if(functionEntered)
computeFunction();
else
cout << "No function entered yet." << endl;
break;
case 5: {
cin.ignore(numeric_limits<streamsize>::max(), '\n');
string msg;
int key;
cout << "Enter message: ";
getline(cin, msg);
cout << "Enter key (0 to 25): ";
cin >> key;
cout << "Encrypted message: " << encryptMessage(msg, key) << endl;
break;
}
case 6:{
cin.ignore(numeric_limits<streamsize>::max(), '\n');
string msg;
int key;
cout<<"Enter encrypted message: ";
getline(cin, msg);
cout<<"Enter key (0 to 25): ";
cin>>key;
cout<<"Decrypted message: "<<decryptMessage(msg, key)<<endl;
break;
}
case 7:
cout<<"Program closed successfully."<<endl;
break;
default:
cout<<"Invalid choice."<<endl;
}
}while(choice != 7);
return 0;
}
