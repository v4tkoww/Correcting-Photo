//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString NameFile;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if(OpenPictureDialog1->Execute()) {
 NameFile = OpenPictureDialog1->FileName;
	 Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
	 Image2->Picture->LoadFromFile(OpenPictureDialog1->FileName);

 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Image2->Picture->LoadFromFile(OpenPictureDialog1->FileName);
//размытие
int division = 44, bias = 0;
int d[5][5];
d[0][0]=1;
d[0][1]=1;
d[0][2]=2;
d[0][3]=1;
d[0][4]=1;

d[1][0]=1;
d[1][1]=2;
d[1][2]=2;
d[1][3]=2;
d[1][4]=1;

d[2][0]=2;
d[2][1]=2;
d[2][2]=8;
d[2][3]=2;
d[2][4]=2;

d[3][0]=1;
d[3][1]=2;
d[3][2]=2;
d[3][3]=2;
d[3][4]=1;

d[4][0]=1;
d[4][1]=1;
d[4][2]=2;
d[4][3]=1;
d[4][4]=1;


	   for (int i = 3; i < Image1->Picture->Width-2; i++) {
	 for (int j = 3; j < Image1->Picture->Height-2; j++) {
		 int r_new = 0, g_new = 0, b_new = 0;

		 for (int k = 0; k < 5; k++) {
		  for (int n = 0; n < 5; n++) {
		  r_new = r_new + GetRValue(Image1->Canvas->Pixels[i-2+k][j-2+n]) * d[k][n];
		  g_new = g_new + GetGValue(Image1->Canvas->Pixels[i-2+k][j-2+n]) * d[k][n];
		  b_new = b_new + GetBValue(Image1->Canvas->Pixels[i-2+k][j-2+n]) * d[k][n];

		  }

		 }
		 r_new = r_new/division + bias;
		 g_new = g_new/division + bias;
		 b_new = b_new/division + bias;
		 Image2->Canvas->Pixels[i][j]=(TColor)RGB(r_new,g_new,b_new);

	 }

}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Image2->Picture->LoadFromFile(OpenPictureDialog1->FileName);
//выделение контуров
int division = 1, bias = 256;
int d[3][3];
d[0][0]=-1;
d[0][1]=-1;
d[0][2]=-1;

d[1][0]=-1;
d[1][1]=9;
d[1][2]=-1;

d[2][0]=-1;
d[2][1]=-1;
d[2][2]=-1;


	   for (int i = 2; i < Image1->Picture->Width-1; i++) {
	 for (int j = 2; j < Image1->Picture->Height-1; j++) {
		 int r_new = 0, g_new = 0, b_new = 0;

		 for (int k = 0; k < 3; k++) {
		  for (int n = 0; n < 3; n++) {
		  r_new = r_new + GetRValue(Image1->Canvas->Pixels[i-1+k][j-1+n]) * d[k][n];
		  g_new = g_new + GetGValue(Image1->Canvas->Pixels[i-1+k][j-1+n]) * d[k][n];
		  b_new = b_new + GetBValue(Image1->Canvas->Pixels[i-1+k][j-1+n]) * d[k][n];

		  }

		 }
		 r_new = r_new/division + bias;
		 g_new = g_new/division + bias;
		 b_new = b_new/division + bias;
		 Image2->Canvas->Pixels[i][j]=(TColor)RGB(r_new,g_new,b_new);

	 }

}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
Image2->Picture->LoadFromFile(OpenPictureDialog1->FileName);
//повышение резкости
int division = 6, bias = 0;
int d[3][3];
d[0][0]=0;
d[0][1]=-1;
d[0][2]=0;

d[1][0]=-1;
d[1][1]=10;
d[1][2]=-1;

d[2][0]=0;
d[2][1]=-1;
d[2][2]=0;


	   for (int i = 2; i < Image1->Picture->Width-1; i++) {
	 for (int j = 2; j < Image1->Picture->Height-1; j++) {
		 int r_new = 0, g_new = 0, b_new = 0;

		 for (int k = 0; k < 3; k++) {
		  for (int n = 0; n < 3; n++) {
		  r_new = r_new + GetRValue(Image1->Canvas->Pixels[i-1+k][j-1+n]) * d[k][n];
		  g_new = g_new + GetGValue(Image1->Canvas->Pixels[i-1+k][j-1+n]) * d[k][n];
		  b_new = b_new + GetBValue(Image1->Canvas->Pixels[i-1+k][j-1+n]) * d[k][n];

		  }

		 }
		 r_new = r_new/division + bias;
		 g_new = g_new/division + bias;
		 b_new = b_new/division + bias;
		 Image2->Canvas->Pixels[i][j]=(TColor)RGB(r_new,g_new,b_new);

	 }


}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
Image2->Picture->LoadFromFile(OpenPictureDialog1->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
Image2->Picture->LoadFromFile(OpenPictureDialog1->FileName);
//имитирующий грубый рисунок цветными карандашами
int division = 1, bias = 128;
int d[5][5];
d[0][0]=-1;
d[0][1]=-1;
d[0][2]=-1;
d[0][3]=-1;
d[0][4]=-1;

d[1][0]=-1;
d[1][1]=-2;
d[1][2]=-2;
d[1][3]=-2;
d[1][4]=-1;

d[2][0]=-1;
d[2][1]=-2;
d[2][2]=34;
d[2][3]=-2;
d[2][4]=-1;

d[3][0]=-1;
d[3][1]=-2;
d[3][2]=-2;
d[3][3]=-2;
d[3][4]=-1;

d[4][0]=-1;
d[4][1]=-1;
d[4][2]=-1;
d[4][3]=-1;
d[4][4]=-1;


	   for (int i = 3; i < Image1->Picture->Width-2; i++) {
	 for (int j = 3; j < Image1->Picture->Height-2; j++) {
		 int r_new = 0, g_new = 0, b_new = 0;

		 for (int k = 0; k < 5; k++) {
		  for (int n = 0; n < 5; n++) {
		  r_new = r_new + GetRValue(Image1->Canvas->Pixels[i-2+k][j-2+n]) * d[k][n];
		  g_new = g_new + GetGValue(Image1->Canvas->Pixels[i-2+k][j-2+n]) * d[k][n];
		  b_new = b_new + GetBValue(Image1->Canvas->Pixels[i-2+k][j-2+n]) * d[k][n];

		  }

		 }
		 r_new = r_new/division + bias;
		 g_new = g_new/division + bias;
		 b_new = b_new/division + bias;
		 r_new = (r_new + g_new + b_new) / 3;
		 Image2->Canvas->Pixels[i][j]=(TColor)RGB(r_new,r_new,r_new);

		 //Image2->Canvas->Pixels[i][j]=(TColor)RGB(r_new,g_new,b_new);

	 }


}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
if (SavePictureDialog1->Execute())
{
Image2->Picture->SaveToFile(SavePictureDialog1->FileName);

}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
Form1->Close();
}
//---------------------------------------------------------------------------
