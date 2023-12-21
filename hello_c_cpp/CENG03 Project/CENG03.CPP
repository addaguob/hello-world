/* 
PC Buying Guide 2006 program, CENG03 project by Alexander Daguob
BS Computer Engineering, AMA Computer College - Bacolod.
Borland C++ IDE
*/
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <string.h>
#include <stdlib.h>
#include <fstream.h>
					
typedef unsigned char BYT;
const BYT specSIZE = 8;
enum BOOL {false, true};
enum COOR {mx, my};

class Form {
public:
	Form();
	int mbhit();
	int mouse_at(int,int,int,int);
	void mouse_off() { regs.x.ax = 2; int86(0x33, &regs, &regs); }
	void plate3d(int,int,int,int,BYT,BYT,BYT);
	void plate(int,int,int,int);
	void button(int,int,char[]);
	void buttonhit(int,int,char[]);
	void textbox(int,int,char*,BYT,BYT,BYT);
	void text(int,int,char[],BYT);
	void cursor(int,int);
	void checkbox(int,int,char[],BYT);
	void buzzform(int,int,int,int);
private:
	union REGS regs;
	int midx, midy;
	int mouseX, mouseY;

};

Form::Form() {
	int gdriver = 0, gmode;
	initgraph(&gdriver, &gmode, "..\\bgi");
	midx = getmaxx()/2;
	midy = getmaxy()/2;
	regs.x.ax = 0; //initialize mouse
	int86(0x33, &regs, &regs);
	regs.x.ax = 4; //initialize coordinates
	regs.x.cx = 50;
	regs.x.dx = 100;
	int86(0x33, &regs, &regs);
}

int Form::mbhit() {
	BYT button = 0;
	regs.x.ax = 1; //show mouse
	int86(0x33, &regs, &regs);
	regs.x.ax = 3; // get coordinates
	int86(0x33, &regs, &regs);
	mouseX = regs.x.cx;
	mouseY = regs.x.dx;
	button = regs.x.bx;
	return button;
}

int Form::mouse_at(int x1, int y1, int width, int height) {
	int status = 0;
	int x2 = x1+width;
	int y2 = y1+height;
	if(mouseX > x1 && x2 > mouseX)
		if(mouseY > y1 && y2 > mouseY)
			status = 1;
	return status;
}

void Form::plate3d(int x1, int y1, int width, int height, BYT upperxy_color, BYT fill_color, BYT lowerxy_color) {
	int x2 = x1+width;
	int y2 = y1+height;
	setcolor(upperxy_color);
	line(x1, y1, x2, y1);
	line(x1, y1, x1, y2);
	setcolor(lowerxy_color);
	line(x2, y1, x2, y2);
	line(x1, y2, x2, y2);
	setfillstyle(1,fill_color);
	bar(x1+1, y1+1, x2-1, y2-1);
	setcolor(7);
}

void Form::plate(int x1, int y1, int width, int height) {
	plate3d(x1,y1,width,height,15,7,8);
}

void Form::buzzform(int x1, int y1, int width, int height) {
	int x2 = x1+width;
	int y2 = y1+height;
	for(BYT color = 0; color <= 15; color++) {
		setcolor(color);
		line(x1, y1, x2, y1);
		line(x1, y1, x1, y2);
		setcolor(color);
		line(x2, y1, x2, y2);
		line(x1, y2, x2, y2);
		delay(15);
	}
	setcolor(15);
	line(x1, y1, x2, y1);
	line(x1, y1, x1, y2);
	setcolor(8);
	line(x2, y1, x2, y2);
	line(x1, y2, x2, y2);
}

void Form::button(int x, int y, char label[]) {
	int width = (strlen(label)*6) + (strlen(label)*2)+6; //march 2008
	plate(x, y, width, 14);
	text(x+4, y+4, label, BLUE);
}

void Form::buttonhit(int x, int y, char label[]) {
	mouse_off();
	int width = (strlen(label)*6) + (strlen(label)*2)+6;
	int x2 = x+width;
	int y2 = y+14;
	setcolor(8);
	line(x, y, x2, y);
	line(x, y, x, y2);
	setcolor(15);
	line(x2, y, x2, y2);
	line(x, y2, x2, y2);
	setfillstyle(1,7);
	bar(x+1, y+1, x2-1, y2-1);
	setcolor(15);
	text(x+4, y+4, label, BLUE);
	delay(100);
	button(x,y,label);
	mbhit();
}
								   // variable | MAX array  i/o use | password type or not?
void Form::textbox(int x1, int y1, char *address, BYT arrSize, BYT input, BYT password) {
	mouse_off();
	int x2 = ((arrSize*6) + (arrSize*2)+6);
	BYT ch = 0;
	char key[2];
	plate3d(x1,y1,x2,14,8,15,7);
	x1+=3; y1+=4;
	if(!input) { // textbox will be used for output
		setcolor(0);
		outtextxy(x1, y1, address);
	} else {       // textbox will be used for input
		BYT eXit = false;
		while(!eXit) {
			while(!kbhit()) {
				cursor(x1,y1);
				if(mbhit()) { eXit = true; break; }
			}
			if(!eXit) {
				address[ch] = getch();
				if(address[ch] != '\r') {
					if(address[ch] == '\b') {
						if(ch > 0) {
							x1-=8;
							setcolor(15);
							key[0] = char(219);
							outtextxy(x1, y1, key);
							ch--;
							address[ch] = ' ';
						}
					} else if(ch < arrSize) {
						if(!password) key[0] = address[ch];
						else key[0] = '*';
						key[1] = '\0';
						setcolor(0);
						outtextxy(x1, y1, key);
						ch++;
						x1+=8;
					}
				} else eXit = true;
			}
		}
		address[ch] = '\0';
		setcolor(15);
	}
}

void Form::text(int x, int y, char txt[], BYT color) {
	setcolor(color);
	outtextxy(x,y,txt);
}

void Form::cursor(int x, int y) {
	setcolor(9);
	line(x,y-1,x,y+8);
	delay(80);
	setcolor(15);
	line(x,y-1,x,y+8);
	delay(80);
}

void Form::checkbox(int x, int y,char txt[],BYT val) {
	plate3d(x,y,8,8,8,15,7);
	if(val) {
		mouse_off();
		text(x+1,y+1,"/",BLACK);
	}
	text(x+13,y+1,txt,BLACK);
}

class SPEC {
	public:
		char name[100];
		char model[30];
		char size[specSIZE];
		BYT checked[3];
		void get_size(int s) {
			itoa(s, size,10);
		}
};

int main() {
	int x, y, x2;
	int specx, specy=20; // distance of SPECS x and y axis
	int specx2, specy2=13;

	int cExit[2]; // coordinates of EXIT button
	int cClear[2]; // coordinates of CLEAR button
	int cSubmit[2]; // coordinates of SUBMIT button

	int cCPU[2][2]; //coor for processors     [1][2] = x1,y1  [2][2] = x2,y2
	int cMB[2][2]; //coor for motherboard
	int cRAM[2][2]; // memory
	int cVGA[2][2]; // Videocard
	int cHDD[3][2]; // Hard disk

	char strCPU[4][15] = {"Processor: ","INTEL ","AMD ","Motherboard: "}; // processor / motherboard
	char strRAM[3][15] = {"Memory/RAM: ","DDR-1 ","DDR-2 "};
	char strVGA[3][20] = {"Videocard/VGA: ","ATI ","NVIDIA "};
	char strHDD[4][20] = {"Hard-disk/HDD: ",
								"SeaGate ","Western Digital ","Samsung "};
	SPEC myCPU, myMB, myRAM, myVGA, myHDD;
	Form f;
  clear_form: // initialize before clearing
	strcpy(myCPU.name, strCPU[0]); //default value
	strcpy(myMB.name, strCPU[3]);
	strcpy(myRAM.name, strRAM[0]);
	strcpy(myVGA.name, strVGA[0]);
	strcpy(myHDD.name, strHDD[0]);
	strcpy(myCPU.model, "(no model) "); //default value
	strcpy(myMB.model, "(no model) ");
	strcpy(myRAM.model, "(no model) ");
	strcpy(myVGA.model, "(no model) ");
	strcpy(myHDD.model, "(no model) ");
	strcpy(myCPU.size, "<size>"); //default value
	strcpy(myRAM.size, "<size>");
	strcpy(myVGA.size, "<size>");
	strcpy(myHDD.size, "<size>");
	for(BYT index=0; index<3; index++)
		myCPU.checked[index] = myMB.checked[index] = myRAM.checked[index] = myVGA.checked[index] = myHDD.checked[index] = false;
  refresh_form:
	cleardevice();
	f.mouse_off();
	f.plate(x=100,y=20,x2=300,400);
	f.plate3d(x+1,y+2,297,20,2,2,2);
	f.text(x+12,y+7,"ThunderPro v.1.0 - PC Buying Guide",WHITE);
	f.text(specx=x+10,y+=35,strCPU[mx],BROWN);               //CPU
	f.checkbox(cCPU[0][mx]=specx2=specx+15,cCPU[0][my]=y+=specy2,strCPU[1],myCPU.checked[0]);
	f.checkbox(cCPU[1][mx]=specx2,cCPU[1][my]=y+=specy2,strCPU[2],myCPU.checked[1]);
	f.text(specx,y+=specy,strCPU[3],BROWN);              //Motherboard
	f.checkbox(cMB[0][mx]=specx2,cMB[0][my]=y+=specy2,strCPU[1],myMB.checked[0]);
	f.checkbox(cMB[1][mx]=specx2,cMB[1][my]=y+=specy2,strCPU[2],myMB.checked[1]);
	f.text(specx,y+=specy,strRAM[0],BROWN);               //Memory
	f.checkbox(cRAM[0][mx]=specx2,cRAM[0][my]=y+=specy2,strRAM[1],myRAM.checked[0]);
	f.checkbox(cRAM[1][mx]=specx2,cRAM[1][my]=y+=specy2,strRAM[2],myRAM.checked[1]);
	f.text(specx,y+=specy,strVGA[0],BROWN);            //Videocard
	f.checkbox(cVGA[0][mx]=specx2,cVGA[0][my]=y+=specy2,strVGA[1],myVGA.checked[0]);
	f.checkbox(cVGA[1][mx]=specx2,cVGA[1][my]=y+=specy2,strVGA[2],myVGA.checked[1]);
	f.text(specx,y+=specy,strHDD[0],BROWN);            //Hard-disk
	f.checkbox(cHDD[0][mx]=specx2,cHDD[0][my]=y+=specy2,strHDD[1],myHDD.checked[0]);
	f.checkbox(cHDD[1][mx]=specx2,cHDD[1][my]=y+=specy2,strHDD[2],myHDD.checked[1]);
	f.checkbox(cHDD[2][mx]=specx2,cHDD[2][1]=y+=specy2,strHDD[3],myHDD.checked[2]);
	f.text(specx,y+=specy,"Others:",BROWN);
	f.text(specx2,y+=specy2,"AVR 500 Watts",BLACK);
	f.text(specx2,y+=specy2,"Optical Mouse",BLACK);
	f.text(specx2,y+=specy2,"Keyboard",BLACK);
	f.text(specx2,y+=specy2,"500 Watts Power Supply",BLACK);
	f.text(specx2,y+=specy2,"Tower Casing",BLACK);
	f.text(specx2,y+=specy2,"DVD/CD R/W",BLACK);
	f.button(cExit[mx]=specx2+x2-70, cExit[my]=y+=specy,"EXIT");
	f.button(cClear[mx]=specx2+x2-121, cClear[my]=y,"CLEAR");
	f.button(cSubmit[mx]=specx2+x2-181, cSubmit[my]=y,"SUBMIT");
	BYT Exit = false;
	while(!Exit) {
		if(f.mbhit()) {
			if(f.mouse_at(cExit[mx],cExit[my],38,14)) {
				f.buttonhit(cExit[mx],cExit[my],"EXIT");
				Exit = true;
			}
			if(f.mouse_at(cClear[mx],cClear[my],46,14)) {
				f.buttonhit(cClear[mx],cClear[my],"CLEAR");
				goto clear_form; // I, C++ Wizard, hereby warn you that "goto" is dangerous for beginners. It can lead to Spaghetti code.
			}
			if(f.mouse_at(cSubmit[mx],cSubmit[my],54,14)) {
				f.buttonhit(cSubmit[mx],cSubmit[my],"SUBMIT");
				strcat(myCPU.name, myCPU.model); //compress model to name
				strcat(myMB.name, myMB.model);
				strcat(myRAM.name, myRAM.model);
				strcat(myVGA.name, myVGA.model);
				strcat(myHDD.name, myHDD.model);
				strcat(myCPU.name, myCPU.size); //compress size to model
				strcat(myRAM.name, myRAM.size);
				strcat(myVGA.name, myVGA.size);
				strcat(myHDD.name, myHDD.size);
				f.plate(x=120,y=50,x2=400,300);
			   buzz_result:
				f.buzzform(x=120,y=50,x2=400,300);
				f.text(x+12,y+=7,"Your PC SPECS:",BLUE);
				f.plate3d(x+=10,y+=specy,x2=380,250,8,15,7);
				f.text(specx=x+=10,y+=specy2,myCPU.name,BLACK);
				f.text(specx,y+=specy2,myMB.name,BLACK);
				f.text(specx,y+=specy2,myRAM.name,BLACK);
				f.text(specx,y+=specy2,myVGA.name,BLACK);
				f.text(specx,y+=specy2,myHDD.name,BLACK);
				f.text(specx,y+=specy,"Others:",8);
				f.text(specx+=10,y+=specy2,"AVR 500 Watts",BLACK);
				f.text(specx,y+=specy2,"Optical Mouse",BLACK);
				f.text(specx,y+=specy2,"Keyboard",BLACK);
				f.text(specx,y+=specy2,"500 Watts Power Supply",BLACK);
				f.text(specx,y+=specy2,"Tower Casing",BLACK);
				f.text(specx,y+=specy2,"DVD/CD R/W",BLACK);
				f.button(x=specx+=20,y+=specy,"ACCEPT");
				while(true) {
					if(f.mbhit()) {
						if(f.mouse_at(x,y,54,14)) {
							f.buttonhit(x,y,"ACCEPT");
							goto clear_form;
						} else goto buzz_result;
					}
				}
			}
			//Processor
			if(f.mouse_at(cCPU[0][mx],cCPU[0][my],46,8)) {
				f.checkbox(cCPU[0][mx],cCPU[0][my],strCPU[1],myCPU.checked[0] = true); //check
				f.checkbox(cCPU[1][mx],cCPU[1][my],strCPU[2],myCPU.checked[1] = false); //uncheck
				strcpy(myCPU.model, strCPU[1]);
				int ix, iy;
				int mc[5][2];
				f.plate(ix=120,iy=cCPU[1][my],300,200);
				f.buzzform(ix=120,iy=cCPU[1][my],300,200); //papansin lang
				f.text(ix+5,iy+5,"Select INTEL model:",RED);
				f.checkbox(mc[0][mx]=ix+=10,mc[0][my]=iy+=specy,"CELERON",0);
				f.checkbox(mc[1][mx]=ix,mc[1][my]=iy+=specy2,"CORE DUO",0);
				f.checkbox(mc[2][mx]=ix,mc[2][my]=iy+=specy2,"CORE2 DUO",0);
				f.text(ix,iy+=specy,"Enter size from 1.6Ghz to 3.2Ghz:",RED);
				f.textbox(mc[3][mx]=ix,mc[3][my]=iy+=specy2,myCPU.size,specSIZE,false,false);
				f.button(mc[4][mx]=ix+10,mc[4][my]=iy+40,"PROCEED");
				BYT nExit = false;
				while(!nExit) {
					if(f.mbhit()) {
						BYT model;
						if(f.mouse_at(mc[4][mx],mc[4][my],54,14)) {
							f.buttonhit(mc[4][mx],mc[4][my],"PROCEED");
							if(model==1) strcat(myCPU.model, "CELERON ");
							if(model==2) strcat(myCPU.model, "CORE DUO ");
							if(model==3) strcat(myCPU.model, "CORE2 DUO ");
							goto refresh_form;
						}
						else if(f.mouse_at(mc[0][mx],mc[0][my],62,8)) {
							model = 1;
							f.checkbox(mc[0][mx],mc[0][my],"CELERON",true);
							f.checkbox(mc[1][mx],mc[1][my],"CORE DUO",false);
							f.checkbox(mc[2][mx],mc[2][my],"CORE2 DUO",false);
						}
						else if(f.mouse_at(mc[1][mx],mc[1][my],62,8)) {
							model = 2;
							f.checkbox(mc[0][mx],mc[0][my],"CELERON",false);
							f.checkbox(mc[1][mx],mc[1][my],"CORE DUO",true);
							f.checkbox(mc[2][mx],mc[2][my],"CORE2 DUO",false);
						}
						else if(f.mouse_at(mc[2][mx],mc[2][my],62,8)) {
							model = 3;
							f.checkbox(mc[0][mx],mc[0][my],"CELERON",false);
							f.checkbox(mc[1][mx],mc[1][my],"CORE DUO",false);
							f.checkbox(mc[2][mx],mc[2][my],"CORE2 DUO",true);
						}
						if(f.mouse_at(mc[3][mx],mc[3][my],62,8)) {
							f.textbox(mc[3][mx],mc[3][my],myCPU.size,specSIZE,true,false);
						}
					}
				}

			}
			if(f.mouse_at(cCPU[1][mx],cCPU[1][my],30,8)) {
				f.checkbox(cCPU[0][mx],cCPU[0][my],strCPU[1],myCPU.checked[0] = false); //check
				f.checkbox(cCPU[1][mx],cCPU[1][my],strCPU[2],myCPU.checked[1] = true); //uncheck

				strcpy(myMB.model, strCPU[3]);
			}
			//MOTHERBOARD
			if(f.mouse_at(cMB[0][mx],cMB[0][my],30,8)) {
				f.checkbox(cMB[0][mx],cMB[0][my],strCPU[1],myMB.checked[0] = true);
				f.checkbox(cMB[1][mx],cMB[1][my],strCPU[2],myMB.checked[1] = false);
				strcpy(myMB.model, strCPU[1]);
				//check compatibility
				if(myCPU.checked[0] != myMB.checked[0]) {
					int ix, iy;
					f.plate(ix=120,iy=120,200,200);
					f.text(ix+2,iy+2,"Sorry, but it's incompatible to your processor!",RED);
					f.text(ix+2,iy+=specy2,"You have to change your",RED);
				}
			}
			if(f.mouse_at(cMB[1][mx],cMB[1][my],30,8)) {
				f.checkbox(cMB[0][mx],cMB[0][my],strCPU[1],myMB.checked[0] = false);
				f.checkbox(cMB[1][mx],cMB[1][my],strCPU[2],myMB.checked[1] = true);
				strcpy(myMB.model, strCPU[2]);

			}
			//Memory
			if(f.mouse_at(cRAM[0][mx],cRAM[0][my],30,8)) {
				f.checkbox(cRAM[0][mx],cRAM[0][my],strRAM[1],myRAM.checked[0] = true);
				f.checkbox(cRAM[1][mx],cRAM[1][my],strRAM[2],myRAM.checked[1] = false);
				strcpy(myRAM.model, strRAM[1]);
			}
			if(f.mouse_at(cRAM[1][mx],cRAM[1][my],30,8)) {
				f.checkbox(cRAM[1][mx],cRAM[1][my],strRAM[2],myRAM.checked[1] = true); //check
				f.checkbox(cRAM[0][mx],cRAM[0][my],strRAM[1],myRAM.checked[0] = false); //uncheck
				strcpy(myRAM.model, strRAM[2]);
			}
			//Videocard
			if(f.mouse_at(cVGA[0][mx],cVGA[0][my],30,8)) {
				f.checkbox(cVGA[0][mx],cVGA[0][my],strVGA[1],myVGA.checked[0] = true);
				f.checkbox(cVGA[1][mx],cVGA[1][my],strVGA[2],myVGA.checked[1] = false);
				strcpy(myVGA.model, strVGA[1]);
			}
			if(f.mouse_at(cVGA[1][mx],cVGA[1][my],40,8)) {
				f.checkbox(cVGA[1][mx],cVGA[1][my],strVGA[2],myVGA.checked[1] = true);
				f.checkbox(cVGA[0][mx],cVGA[0][my],strVGA[1],myVGA.checked[0] = false);
				strcpy(myVGA.model, strVGA[2]);
			}
			//Hard-disk
			if(f.mouse_at(cHDD[0][mx],cHDD[0][my],30,8)) {
				f.checkbox(cHDD[0][mx],cHDD[0][my],strHDD[1],myHDD.checked[0] = true);
				f.checkbox(cHDD[1][mx],cHDD[1][my],strHDD[2],myHDD.checked[1] = false);
				f.checkbox(cHDD[2][mx],cHDD[2][my],strHDD[3],myHDD.checked[2] = false);
				strcpy(myHDD.model, strHDD[1]);
			}
			if(f.mouse_at(cHDD[1][mx],cHDD[1][my],130,8)) {
				f.checkbox(cHDD[0][mx],cHDD[0][my],strHDD[1],myHDD.checked[0] = false);
				f.checkbox(cHDD[1][mx],cHDD[1][my],strHDD[2],myHDD.checked[1] = true);
				f.checkbox(cHDD[2][mx],cHDD[2][my],strHDD[3],myHDD.checked[2] = false);
				strcpy(myHDD.model, strHDD[2]);
			}
			if(f.mouse_at(cHDD[2][mx],cHDD[2][my],30,8)) {
				f.checkbox(cHDD[0][mx],cHDD[0][my],strHDD[1],myHDD.checked[0] = false);
				f.checkbox(cHDD[1][mx],cHDD[1][my],strHDD[2],myHDD.checked[1] = false);
				f.checkbox(cHDD[2][mx],cHDD[2][my],strHDD[3],myHDD.checked[2] = true);
				strcpy(myHDD.model, strHDD[3]);
			}
		}

	}
	closegraph();
	return 0;
}