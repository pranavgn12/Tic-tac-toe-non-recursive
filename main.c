#include "time.h"
#include "math.h"
# define pi 3.1415
#include "stdlib.h"
#include "stddef.h" 
#include "raylib.h"
#include "arial_data.h" 
#define res 100
int r;
int a[3][3];
int i, j, k, l, g, jg, cn;
float m, n, o;
float c;
Font Ar;
Vector2 t;
const Color lg = { 220, 220, 220, 250 };
/*void drawX(int x, int y){
	DrawLineEx((Vector2) {x,y},(Vector2) {x+150-35,y+150-35}, 10, BLACK);
	DrawLineEx((Vector2) {x+150-35,y},(Vector2) {x,y+150-35}, 10, BLACK);
}*/

void draw() {
	ClearBackground(WHITE);
	if (r == 1)
		DrawTextEx(Ar, "X's Turn", t, 70, 1, BLACK);
	else
		DrawTextEx(Ar, "O's Turn", t, 70, 1, BLACK);
	if (i == 0 && j == 0) {
		DrawCircle(174 + 10, 174 + 10, 10, lg);
		DrawRectangle(174 + 10, 174, 150 - 10, 150, lg);
		DrawRectangle(174, 174 + 10, 10, 150 - 10, lg);
	}
	else if (i == 2 && j == 0) {
		DrawCircle(626 - 10, 174 + 10, 10, lg);
		DrawRectangle(626 - 150, 174, 150 - 10, 150, lg);
		DrawRectangle(626 - 10, 174 + 10, 10, 150 - 10, lg);
	}
	else if (i == 0 && j == 2) {
		DrawCircle(174 + 10, 626 - 10, 10, lg);
		DrawRectangle(174 + 10, 626 - 150, 150 - 10, 150, lg);
		DrawRectangle(174, 626 - 150, 10, 150 - 10, lg);
	}
	else if (i == 2 && j == 2) {
		DrawCircle(626 - 10, 626 - 10, 10, lg);
		DrawRectangle(626 - 150, 626 - 150, 150 - 10, 150, lg);
		DrawRectangle(626 - 10, 626 - 150, 10, 150 - 10, lg);
	}
	else
		DrawRectangle(174 + 150 * i, 174 + 150 * j, 150, 150, lg);
	//if()


	for (k = 0; k < 2; k++) {
		DrawRectangle(320.66 + 150.66 * k - 4, 174, 8, 453, BLACK);
		DrawRectangle(174, 320.66 + 150.66 * k - 4, 453, 8, BLACK);
	}

	for (l = 0; l < 3; l++) {
		for (k = 0; k < 3; k++) {
			if (a[k][l] == 1) {
				DrawLineEx((Vector2) { 174 + 150 * k + 35, 174 + 150 * l + 35 }, (Vector2) { 174 + 150 * (k + 1) - 35, 174 + 150 * (l + 1) - 35 }, 10, BLACK);
				DrawLineEx((Vector2) { 174 + 150 * (k + 1) - 35, 174 + 150 * l + 35 }, (Vector2) { 174 + 150 * k + 35, 174 + 150 * (l + 1) - 35 }, 10, BLACK);
			}
			else if (a[k][l] == 2) {
				m = res;
				n = 360 / m;
				o = 45;
				for (; m > 0; m--) {
					DrawLineEx((Vector2) { 174 + 150 * k + 75 + o * sin((360 - m * n) * pi / 180), 174 + 150 * l + 75 + o * cos((360 - m * n) * pi / 180) }, (Vector2) { 174 + 150 * k + 75 + o * sin((360 - (m - 1) * n) * pi / 180), 174 + 150 * l + 75 + o * cos((360 - (m - 1) * n) * pi / 180) }, 10, BLACK);
					DrawCircle(174 + 150 * k + 75 + o * sin((360 - (m - 1) * n) * pi / 180), 174 + 150 * l + 75 + o * cos((360 - (m - 1) * n) * pi / 180), 5, BLACK);
				}

				//DrawCircleSectorLines((Vector2) {174+150*k+75,174+150*l+75}, 60, 0, 360, 5, BLACK);
			}
		}
	}

}

int ev(int* a, int i, int j) {
	if (*(a + 3 * i + 0) != 0 && *(a + 3 * i + 0) == *(a + 3 * i + 1) && *(a + 3 * i + 1) == *(a + 3 * i + 2)) //checks row
		return 1;
	else if (*(a + 3 * 0 + j) != 0 && *(a + 3 * 0 + j) == *(a + 3 * 1 + j) && *(a + 3 * 1 + j) == *(a + 3 * 2 + j)) //checks column
		return 1;
	else if (*(a + 3 * 0 + 0) != 0 && *(a + 3 * 0 + 0) == *(a + 3 * 1 + 1) && *(a + 3 * 1 + 1) == *(a + 3 * 2 + 2)) //checks 1st diagonal
		return 1;
	else if (*(a + 3 * 0 + 2) != 0 && *(a + 3 * 0 + 2) == *(a + 3 * 1 + 1) && *(a + 3 * 1 + 1) == *(a + 3 * 2 + 0)) //checks 2nd diagonal
		return 1;
	return 0;
}


 int find_move(int *a, int t){
	 int c=0,l=0,i,j,v,e;
	 for(i=0; i<3; i++)
		 for(j=0; j<3; j++)
			 if(*(a+3*i+j)==0)
				 c++;
	/////////////////Memory Allocated ///////////////////////////////////////
	 int** m= (int**) malloc((c)*sizeof(int*));
	 int** s= (int**) malloc((c)*sizeof(int*));
	 int* p=  (int*) malloc((c)*sizeof(int));
	 for(i=0;i<c; i++){
		*(m+i)= (int*) malloc ((c)*sizeof(int));
		*(s+i)= (int*) malloc ((c)*sizeof(int));
	}					
	 /**m= (int*) malloc ((c)*sizeof(int));
	 *s= (int*) malloc ((c)*sizeof(int));*/
	// printf("%d\n",c);
	 *p=0;
	 *(*(m)+(*(p+l)))=0;
	 while(l>-1){
		//printf("Entered l1\n");
			while(c>0 && (*(p+l))<c){
				//printf("Entered l2\n %d",c);
				//pr(a);
				//getch();
				//printf("%d\n",(*((*(m+l))+(*(p+l)))));
				
				while((*((*(m+l))+(*(p+l))))<9 && (*(a+(*((*(m+l))+(*(p+l))))))!=0 ){
						(*((*(m+l))+(*(p+l))))++;														
				}
				
				if((*((*(m+l))+(*(p+l))))==9)
				exit(0);
				//printf("%d\n",(*(s+l)));
				*(a+(*((*(m+l))+(*(p+l)))))=t;
				//pr(a);
				//getch();
				if(ev(a,(*((*(m+l))+(*(p+l))))/3,(*((*(m+l))+(*(p+l))))%3)==1){
				*((*(s+l))+(*(p+l))) = t >1 ? -10+l : 10-l; 				//////////////////////////////////////////////////////////////////////////////////
				*(a+(*((*(m+l))+(*(p+l)))))=0;
				(*(p+l))++;
				if((*(p+l))<c)
				(*((*(m+l))+(*(p+l))))=(*((*(m+l))+(*(p+l))-1))+1;         //////////////////////////////////////////////////////////////////////////
				}
				else{
					//if(c>0)
						//printf("ins\n");
						//getch();
					
					c--;
					if(c>0){
					t= t>1? 1: 2;
					l++;
					*(p+l)=0;                                         
					/**(m+l)= (int*) malloc ((c)*sizeof(int));
					*(s+l)= (int*) malloc ((c)*sizeof(int));*/
					*((*(m+l))+*(p+l))=0;                            //////////////////////////////////////////////////////////////////////////////
					}
					/*else{
					printf("%d %d\n",c,(*(p+l)));
					getch();}*/
					
				}
			}
			
			//printf("jj\n");
			if(c==0){
			*((*(s+l))+(*(p+l)))=0;                                 /////////////////////////////////////////////////////////////////
			c++;
			}
			else
				(*(p+l))--;
			/*printf("scroes----%d\n",t);
			for(int qq=0; qq<c; qq++)
			printf("%d ",*(*(m+l)+qq));
			printf("\n");
			for(int qq=0; qq<c; qq++)
			printf("%d ",*(*(s+l)+qq));*/
		//getch();
			//if(l=0)
				//t= t>1? 1: 2;
			if(t>1){
				//printf("11111111111");
				for(i=0,e=0,v=10; i<c;i++){
					if((*((*(s+l))+i))<v){
						e=i;
					v=(*((*(s+l))+i));
				}}
			}
			else{
					//printf("2222222");

					for(i=0,e=0,v=-10; i<c;i++)
					if((*((*(s+l))+i))>v){
						e=i;
						v=(*((*(s+l))+i));
			}}
			//if(ev(a,(*((*(m+l))+(*(p+l))))/3,(*((*(m+l))+(*(p+l))))%3)==1)
			//if(c!=0)

			//printf("ii %d c %d\n",l,c);
			//getch();
			/*if(ev(a,(*((*(m+l))+(*(p+l))-1))/3,(*((*(m+l))+(*(p+l))-1))%3)==1)*/
			
			//printf("gg\n");
			*(a+(*((*(m+l))+(*(p+l)))))=0;
			//pr(a);
			//getch();
			/*if(l!=pl){
				printf("heheheh");
				getch();
			}*/
			//if(l!=pl){
			/*free(*(m+l));
			free(*(s+l));*/
			//}
			
			//pl=l;
			l--;
			t= t>1? 1: 2;
			if(l>-1){
			c++;
			//printf("a\n");
			
			*((*(s+l))+(*(p+l)))=v;                                                           ////////////////////////////////////////////////////////
			*(a+(*((*(m+l))+(*(p+l)))))=0;
			
			(*(p+l))++;
			if((*(p+l))<c){			
			(*((*(m+l))+(*(p+l))))=(*((*(m+l))+(*(p+l))-1))+1;                                ////////////////////////////////////////////////////////
					/*printf("%d %d\n",*(*(s+l)),*(*(s+l)+1));
					printf("%d %d\n",*(*(m+l)),*(*(m+l)+1));
					getch();*/
			/*printf("---------------------------%d l-%d\n",(*(p+l)),l);
			printf("scroes----\n");
			for(int qq=0; qq<c; qq++)
			printf("%d ",*(*(m+l)+qq));
			printf("\n");
			for(int qq=0; qq<c; qq++)
			printf("%d ",*(*(s+l)+qq));*/
			//getch();
			}}

			}
		/*printf("\n");
		for(int qq=0; qq<c; qq++)
			printf("%d ",*(*(m)+qq));
		printf("\n");
		for(int qq=0; qq<c; qq++)
			printf("%d ",*(*(s)+qq));*/
		l++;
		if(t>1){
				//printf("11111111111");
				for(i=0,e=0,v=-10; i<c;i++){
					if((*((*(s+l))+i))>v){
						e=i;
					v=(*((*(s+l))+i));
				}}
			}
			else{
								//printf("2222222");

					for(i=0,e=0,v=10; i<c;i++)
					if((*((*(s+l))+i))<v){											
						e=i;
						v=(*((*(s+l))+i));
			}}
		
		v=*((*(m))+e);
		//printf("ddddd--------------------------------------------");
///////////How to free memory?////////////////////////////
		//getch();
		for(i=0;i<c; i++){
		free(*(m+i));
		free(*(s+i));
		}					
		free(m);
		free(s);
		free(p);
		return (v);
	 }






int main(void)
{
	// Initialization
	//---------------------------------------------------  -----------------------------------
	SetRandomSeed(time(NULL));
    const int screenWidth = 800;
	const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Tic Tac Toe");
	//SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	//int a[3][3]={{0,0,0},{0,0,0},{0,0,0}};
	
	Ar = LoadFontFromMemory(".ttf", arial_ttf, arial_ttf_len, 100, 0, 0);
	SetConfigFlags(FLAG_MSAA_4X_HINT);
	SetTargetFPS(45);
	
	BeginDrawing();
st: cn = 0;
	for (k = 0; k < 3; k++)
		for (l = 0; l < 3; l++)
			a[k][l] = 0;


	t.x = 250;
	t.y = 20;

	/*lg.r=220;
	lg.g=220;
	lg.b=220;
	lg.a=250;*/
	// Vector2 b;   
	for (i = 626, c = 0; c < 1.04 && !WindowShouldClose(); i = 400.5 - 226.5 * c * (2 - c), c += 0.04)
	{
		ClearBackground(WHITE);
		//DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);
	   // DrawTextEx(Ar, "Tic Tac Toe", a, 70, 1, BLACK);
		//DrawText(q , 180, 20, 70, BLACK); 
		//DrawTextEx(Ar, "Tic Tac Toe", t, 70, 1, BLACK);

		for (j = 0; j < 2; j++) {
			DrawRectangle(320.66 + 150.66 * j - 4, i, 8, 2 * 226.5 * c * (2 - c), BLACK);
			DrawRectangle(i, 320.66 + 150.66 * j - 4, 2 * 226.5 * c * (2 - c), 8, BLACK);
		}
		EndDrawing();
	}

	r = GetRandomValue(1, 2);







	while (!WindowShouldClose()) {
		if (GetMouseX() > 174 && GetMouseX() < 626 && GetMouseY() > 174 && GetMouseY() < 626) {
			i = (GetMouseX() - 174) / 150.66;
			j = (GetMouseY() - 174) / 150.66;
		}
		draw();
		EndDrawing();
		if (r == 2)
		{
		re: /*i=GetRandomValue(0,2);
			j=GetRandomValue(0,2);*/
			int tq;
			for (int ww = 0; ww < 2; ww++)
				for (int kk = ww + 1; kk < 3; kk++) {
					tq = a[kk][ww];
					a[kk][ww] = a[ww][kk];
					a[ww][kk] = tq;
				}

			jg = find_move(&a[0][0], 2);

			for (int ww = 0; ww < 2; ww++)
				for (int kk = ww + 1; kk < 3; kk++) {
					tq = a[kk][ww];
					a[kk][ww] = a[ww][kk];
					a[ww][kk] = tq;
				}


			i = jg % 3;
			j = jg / 3;

			if (a[i][j] == 0) {
				cn++;
				draw();
				EndDrawing();
				draw();
				EndDrawing();
				for (k = 0, c = 0; c < 1.04 && !WindowShouldClose(); k = 360 * c * (2 - c), c += 0.04) {
					m = res;
					n = k / m;
					o = 45;
					for (; m > 0; m--) {
						DrawLineEx((Vector2) { 174 + 150 * i + 75 - o * sin((360 - m * n) * pi / 180), 174 + 150 * j + 75 - o * cos((360 - m * n) * pi / 180) }, (Vector2) { 174 + 150 * i + 75 - o * sin((360 - (m - 1) * n) * pi / 180), 174 + 150 * j + 75 - o * cos((360 - (m - 1) * n) * pi / 180) }, 10, BLACK);
						DrawCircle(174 + 150 * i + 75 - o * sin((360 - (m - 1) * n) * pi / 180), 174 + 150 * j + 75 - o * cos((360 - (m - 1) * n) * pi / 180), 5, BLACK);
					}
					EndDrawing();
				}
				/*for(;m>1;m--){
					DrawLineEx((Vector2) {174+150*i+75+o*cos((360-m*n)),174+150*j+75+o*sin((360-m*n))},(Vector2) {174+150*i+75+o*cos((360-(m-1)*n)),174+150*j+75+o*sin((360-(m-1)*n))}, 10, BLACK);
					EndDrawing();
					}*/
					//DrawCircleSectorLines((Vector2) {174+150*i+75,174+150*j+75}, 60, 0, 360, 5, BLACK); 

				a[i][j] = 2;
				r = 1;
			}
			else
				goto re;
		}



		if (r == 1) {
			if (IsMouseButtonDown(0)) {
				if (a[i][j] == 0) {
					cn++;
					draw();
					a[i][j] = 1;
					for (k = 115, c = 0; c < 1.04 && !WindowShouldClose(); k = 115 - 80 * c * (2 - c), c += 0.04) {
						DrawLineEx((Vector2) { 174 + 150 * i + 35, 174 + 150 * j + 35 }, (Vector2) { 174 + 150 * (i + 1) - k, 174 + 150 * (j + 1) - k }, 10, BLACK);
						DrawLineEx((Vector2) { 174 + 150 * (i + 1) - 35, 174 + 150 * j + 35 }, (Vector2) { 174 + 150 * i + k, 174 + 150 * (j + 1) - k }, 10, BLACK);
						EndDrawing();
					}
					r = 2;
				}
			}
		}
		if (a[0][j] != 0 && a[0][j] == a[1][j] && a[1][j] == a[2][j]) {

			if (a[0][j] == 1) {
				for (k = 174, c = 0; c < 1.02 && !WindowShouldClose(); k = 174 + 452 * c * (2 - c), c += 0.02) {
					DrawLineEx((Vector2) { 174, 174 + 150 * j + 75 }, (Vector2) { k, 174 + 150 * j + 75 }, 10, RED);
					EndDrawing();
				}

				switch (j) {
				case 0: jg = 1; break;
				case 1: jg = 0; break;
				case 2: jg = -1;
				}

				for (g = 0, c = 0; c < 1.025 && !WindowShouldClose(); g = jg * 150 * c * (2 - c), c += 0.025) {

					ClearBackground((Color) { 250, 250, 250, 250 });
					i = -999;
					draw();
					DrawRectangle(174, 174 + 150 * j, 150, 150, WHITE);
					DrawRectangle(174 + 150, 174 + 150 * j, 150, 150, WHITE);
					DrawRectangle(174 + 300, 174 + 150 * j, 150, 150, WHITE);

					for (k = 0; k < 2; k++) {
						DrawRectangle(320.66 + 150.66 * k - 4, 174, 8, 453, BLACK);
						DrawRectangle(174, 320.66 + 150.66 * k - 4, 453, 8, BLACK);
					}

					DrawLineEx((Vector2) { 174 + 150 * 0 + 35 + 150 * c * (2 - c), 174 + 150 * j + 35 + g }, (Vector2) { 174 + 150 + 150 * c * (2 - c) - 35, 174 + 150 * (j + 1) - 35 + g }, 10, BLACK);
					DrawLineEx((Vector2) { 174 + 150 + 150 * c * (2 - c) - 35, 174 + 150 * j + 35 + g }, (Vector2) { 174 + 150 * c * (2 - c) + 35, 174 + 150 * (j + 1) - 35 + g }, 10, BLACK);

					DrawLineEx((Vector2) { 174 + 150 + 35, 174 + 150 * j + 35 + g }, (Vector2) { 174 + 150 * 2 - 35, 174 + 150 * (j + 1) - 35 + g }, 10, BLACK);
					DrawLineEx((Vector2) { 174 + 300 - 35, 174 + 150 * j + 35 + g }, (Vector2) { 174 + 150 + 35, 174 + 150 * (j + 1) - 35 + g }, 10, BLACK);


					DrawLineEx((Vector2) { 174 + 150 * 2 + 35 - 150 * c * (2 - c), 174 + 150 * j + 35 + g }, (Vector2) { 174 + 150 * 3 - 150 * c * (2 - c) - 35, 174 + 150 * (j + 1) - 35 + g }, 10, BLACK);
					DrawLineEx((Vector2) { 174 + 150 * 3 - 150 * c * (2 - c) - 35, 174 + 150 * j + 35 + g }, (Vector2) { 174 + 150 * 2 - 150 * c * (2 - c) + 35, 174 + 150 * (j + 1) - 35 + g }, 10, BLACK);






					DrawLineEx((Vector2) { 174 + (150 + 75) * c * (2 - c), 174 + 150 * j + 75 + g }, (Vector2) { 626 - (150 + 75) * c * (2 - c), 174 + 150 * j + 75 + g }, 10, BLACK);
					EndDrawing();
				}



				EndDrawing();

				ClearBackground((Color) { k, 250, 250, 250 });

				draw();
				DrawRectangle(174, 174 + 150 * j, 142, 142, WHITE);
				DrawRectangle(174 + 150, 174 + 150 * j, 142, 142, WHITE);
				DrawRectangle(174 + 300, 174 + 150 * j, 142, 142, WHITE);



				DrawLineEx((Vector2) { 174 + 150 * 0 + 35 + 150 * c * (2 - c), 174 + 150 * j + 35 + g }, (Vector2) { 174 + 150 + 150 * c * (2 - c) - 35, 174 + 150 * (j + 1) - 35 + g }, 10, BLACK);
				DrawLineEx((Vector2) { 174 + 150 + 150 * c * (2 - c) - 35, 174 + 150 * j + 35 + g }, (Vector2) { 174 + 150 * c * (2 - c) + 35, 174 + 150 * (j + 1) - 35 + g }, 10, BLACK);

				DrawLineEx((Vector2) { 174 + 150 + 35, 174 + 150 * j + 35 + g }, (Vector2) { 174 + 150 * 2 - 35, 174 + 150 * (j + 1) - 35 + g }, 10, BLACK);
				DrawLineEx((Vector2) { 174 + 300 - 35, 174 + 150 * j + 35 + g }, (Vector2) { 174 + 150 + 35, 174 + 150 * (j + 1) - 35 + g }, 10, BLACK);


				DrawLineEx((Vector2) { 174 + 150 * 2 + 35 - 150 * c * (2 - c), 174 + 150 * j + 35 + g }, (Vector2) { 174 + 150 * 3 - 150 * c * (2 - c) - 35, 174 + 150 * (j + 1) - 35 + g }, 10, BLACK);
				DrawLineEx((Vector2) { 174 + 150 * 3 - 150 * c * (2 - c) - 35, 174 + 150 * j + 35 + g }, (Vector2) { 174 + 150 * 2 - 150 * c * (2 - c) + 35, 174 + 150 * (j + 1) - 35 + g }, 10, BLACK);






				DrawLineEx((Vector2) { 174 + (150 + 75) * c * (2 - c), 174 + 150 * j + 75 + g }, (Vector2) { 626 - (150 + 75) * c * (2 - c), 174 + 150 * j + 75 + g }, 10, BLACK);
				EndDrawing();







				//for(k=174,c=0; c<1.04 && !WindowShouldClose(); k=174+452*c*(2-c), c+=0.04){
				   /*for(int aa=0 ; aa<50 && !WindowShouldClose() ; aa++) {
				   DrawRectangle(0, 0, 800, 800,(Color){255,255,255,51});


				   DrawLineEx((Vector2) {174+150+35,174+150+35},(Vector2) {174+150*2-35,174+150*2-35}, 10, BLACK);
				   DrawLineEx((Vector2) {174+300-35,174+150+35},(Vector2) {174+150+35,174+150*2-35}, 10, BLACK);
				   EndDrawing();}*/


				   /*ClearBackground(WHITE);
				   DrawLineEx((Vector2) {174+150+35,174+150+35},(Vector2) {174+150*2-35,174+150*2-35}, 10, BLACK);
					DrawLineEx((Vector2) {174+300-35,174+150+35},(Vector2) {174+150+35,174+150*2-35}, 10, BLACK);
				   EndDrawing();
				   ClearBackground(WHITE);
				   DrawLineEx((Vector2) {174+150+35,174+150+35},(Vector2) {174+150*2-35,174+150*2-35}, 10, BLACK);
				   DrawLineEx((Vector2) {174+300-35,174+150+35},(Vector2) {174+150+35,174+150*2-35}, 10, BLACK);
				   EndDrawing();*/
				k = 0;
				for (g = 0, c = 0; c < 1.05 && !WindowShouldClose(); g = 35 * c * (2 - c), c += 0.05) {

					DrawRectangle(0, 0, 800, 800, (Color) { 255, 255, 255, 75 });
					//ClearBackground(WHITE);
					DrawLineEx((Vector2) { 174 + 150 + 35 - g, 174 + 150 + 35 - g }, (Vector2) { 174 + 150 * 2 - 35 + g, 174 + 150 * 2 - 35 + g }, 10 + g / 3.5, BLACK);
					DrawLineEx((Vector2) { 174 + 150 * 2 - 35 + g, 174 + 150 + 35 - g }, (Vector2) { 174 + 150 + 35 - g, 174 + 150 * 2 - 35 + g }, 10 + g / 3.5, BLACK);
					EndDrawing();
					DrawRectangle(0, 0, 800, 800, (Color) { 255, 255, 255, 75 });
					DrawLineEx((Vector2) { 174 + 150 + 35 - g, 174 + 150 + 35 - g }, (Vector2) { 174 + 150 * 2 - 35 + g, 174 + 150 * 2 - 35 + g }, 10 + g / 3.5, BLACK);
					DrawLineEx((Vector2) { 174 + 150 * 2 - 35 + g, 174 + 150 + 35 - g }, (Vector2) { 174 + 150 + 35 - g, 174 + 150 * 2 - 35 + g }, 10 + g / 3.5, BLACK);
					EndDrawing();

					//k=255*c*(2-c);
				}

				i = 0;
				goto w;





			}
			else if (a[0][j] == 2) {

				for (k = 174, c = 0; c < 1.02 && !WindowShouldClose(); k = 174 + 452 * c * (2 - c), c += 0.02) {
					DrawLineEx((Vector2) { 174, 174 + 150 * j + 75 }, (Vector2) { k, 174 + 150 * j + 75 }, 10, RED);
					EndDrawing();
				}
				switch (j) {
				case 0: jg = 1; break;
				case 1: jg = 0; break;
				case 2: jg = -1;
				}
				for (g = 0, c = 0; c < 1.025 && !WindowShouldClose(); g = jg * 150 * c * (2 - c), c += 0.025) {

					DrawRectangle(0, 0, 800, 800, (Color) { 255, 255, 255, 75 });
					i = -999;
					draw();
					DrawRectangle(174, 174 + 150 * j, 142, 142, WHITE);
					DrawRectangle(174 + 150, 174 + 150 * j, 142, 142, WHITE);
					DrawRectangle(174 + 300, 174 + 150 * j, 142, 142, WHITE);

					m = res;
					n = 360 / m;
					o = 45;
					for (; m > 0; m--) {
						DrawLineEx((Vector2) { 174 + 150 * c * (2 - c) + 150 * 0 + 75 + o * sin((360 - m * n) * pi / 180), 174 + g + 150 * j + 75 + o * cos((360 - m * n) * pi / 180) }, (Vector2) { 174 + 150 * c * (2 - c) + 150 * 0 + 75 + o * sin((360 - (m - 1) * n) * pi / 180), 174 + g + 150 * j + 75 + o * cos((360 - (m - 1) * n) * pi / 180) }, 10, BLACK);
						DrawCircle(174 + 150 * c * (2 - c) + 150 * 0 + 75 + o * sin((360 - (m - 1) * n) * pi / 180), 174 + g + 150 * j + 75 + o * cos((360 - (m - 1) * n) * pi / 180), 5, BLACK);

						DrawLineEx((Vector2) { 174 + 150 + 0 * 150 * c * (2 - c) + 150 * 0 + 75 + o * sin((360 - m * n) * pi / 180), 174 + g + 150 * j + 75 + o * cos((360 - m * n) * pi / 180) }, (Vector2) { 174 + 150 + 0 * 150 * c * (2 - c) + 150 * 0 + 75 + o * sin((360 - (m - 1) * n) * pi / 180), 174 + g + 150 * j + 75 + o * cos((360 - (m - 1) * n) * pi / 180) }, 10, BLACK);
						DrawCircle(174 + 150 + 0 * 150 * c * (2 - c) + 150 * 0 + 75 + o * sin((360 - (m - 1) * n) * pi / 180), 174 + g + 150 * j + 75 + o * cos((360 - (m - 1) * n) * pi / 180), 5, BLACK);

						DrawLineEx((Vector2) { 174 + 2 * 150 + -1 * 150 * c * (2 - c) + 150 * 0 + 75 + o * sin((360 - m * n) * pi / 180), 174 + g + 150 * j + 75 + o * cos((360 - m * n) * pi / 180) }, (Vector2) { 174 + 2 * 150 + -1 * 150 * c * (2 - c) + 150 * 0 + 75 + o * sin((360 - (m - 1) * n) * pi / 180), 174 + g + 150 * j + 75 + o * cos((360 - (m - 1) * n) * pi / 180) }, 10, BLACK);
						DrawCircle(174 + 2 * 150 + -1 * 150 * c * (2 - c) + 150 * 0 + 75 + o * sin((360 - (m - 1) * n) * pi / 180), 174 + g + 150 * j + 75 + o * cos((360 - (m - 1) * n) * pi / 180), 5, BLACK);

					}

					DrawLineEx((Vector2) { 174 + (150 + 75) * c * (2 - c), 174 + 150 * j + 75 + g }, (Vector2) { 626 - (150 + 75) * c * (2 - c), 174 + 150 * j + 75 + g }, 10, BLACK);





					EndDrawing();
				}

				i = 1; goto w;



			}
		}
		else if (a[i][0] != 0 && a[i][0] == a[i][1] && a[i][1] == a[i][2]) {

			if (a[i][0] == 1) {
				for (k = 174, c = 0; c < 1.02 && !WindowShouldClose(); k = 174 + 452 * c * (2 - c), c += 0.02) {
					DrawLineEx((Vector2) { 174 + 150 * i + 75, 174 }, (Vector2) { 174 + 150 * i + 75, k }, 10, RED);
					EndDrawing();
				}i = 0; goto w;
			}
			else if (a[i][0] == 2) {
				for (k = 174, c = 0; c < 1.04 && !WindowShouldClose(); k = 174 + 452 * c * (2 - c), c += 0.04) {
					DrawLineEx((Vector2) { 174 + 150 * i + 75, 174 }, (Vector2) { 174 + 150 * i + 75, k }, 10, RED);
					EndDrawing();
				}
				i = 1; goto w;
			}
		}
		else if (a[0][0] != 0 && a[0][0] == a[1][1] && a[1][1] == a[2][2]) {

			if (a[0][0] == 1) {//DrawTextEx(Ar, "DDDDDD", t, 70, 1, BLACK);
				for (k = 174, c = 0; c < 1.02 && !WindowShouldClose(); k = 174 + 452 * c * (2 - c), c += 0.02) {
					DrawLineEx((Vector2) { 174, 174 }, (Vector2) { k, k }, 10, RED);
					EndDrawing();
				}
				i = 0; goto w;
			}
			else if (a[0][0] == 2) {
				for (k = 174, c = 0; c < 1.04 && !WindowShouldClose(); k = 174 + 452 * c * (2 - c), c += 0.04) {
					DrawLineEx((Vector2) { 174, 174 }, (Vector2) { k, k }, 10, RED);
					EndDrawing();
				}i = 1; goto w;
			}
		}

		else if (a[2][0] != 0 && a[2][0] == a[1][1] && a[1][1] == a[0][2]) {
			if (a[2][0] == 1) {
				for (k = 174, c = 0; c < 1.02 && !WindowShouldClose(); k = 174 + 452 * c * (2 - c), c += 0.02) {
					DrawLineEx((Vector2) { 626, 174 }, (Vector2) { 800 - k, k }, 10, RED);
					EndDrawing();
				}
				i = 0; goto w;
			}
			else if (a[2][0] == 2) {
				for (k = 174, c = 0; c < 1.02 && !WindowShouldClose(); k = 174 + 452 * c * (2 - c), c += 0.02) {
					DrawLineEx((Vector2) { 626, 174 }, (Vector2) { 800 - k, k }, 10, RED);
					EndDrawing();
				}i = 1; goto w;
			}
		}
		/* =else if(a[i][1]==2 && a[i][1]==a[i][2] && a[i][2]==a[i][3]){
			  DrawTextEx(Ar, "hh", t, 70, 1, BLACK);
			   EndDrawing();}*/

		if (cn == 9)
		{
			i = 2; goto w;
		}

	}

w:  c = 0;
	while (!WindowShouldClose()) {
		ClearBackground(WHITE);

		if (i == 0 || i == 1)
			DrawTextEx(Ar, "WINNER!", (Vector2) { 245, 174 }, 90, 1, BLACK);
		else
			DrawTextEx(Ar, "TIE!", (Vector2) { 300, 310 }, 90, 1, BLACK);

		if (i == 0) {
			DrawLineEx((Vector2) { 174 + 150, 174 + 150 }, (Vector2) { 174 + 150 * 2, 174 + 150 * 2 }, 20, BLACK);
			DrawLineEx((Vector2) { 174 + 300, 174 + 150 }, (Vector2) { 174 + 150, 174 + 150 * 2 }, 20, BLACK);
		}
		else if (i == 1) {
			m = res;
			n = 360 / m;
			o = 100;
			for (; m > 0 && !WindowShouldClose(); m--) {
				DrawLineEx((Vector2) { 174 + 226 + o * sin((360 - m * n) * pi / 180), 174 + 226 + o * cos((360 - m * n) * pi / 180) }, (Vector2) { 174 + 226 + o * sin((360 - (m - 1) * n) * pi / 180), 174 + 226 + o * cos((360 - (m - 1) * n) * pi / 180) }, 10, BLACK);
				DrawCircle(174 + 226 + o * sin((360 - (m - 1) * n) * pi / 180), 174 + 226 + o * cos((360 - (m - 1) * n) * pi / 180), 5, BLACK);
			}
		}



		if (GetMouseX() > 144 && GetMouseX() < 800 - 144 && GetMouseY() > 600 && GetMouseY() < 800 - 104) {
			if (IsMouseButtonDown(0))
				goto st;
			if (c < 1.06) {
				c += 0.03;
			}
		}
		else {
			if (c > 0)
				c -= 0.03;
		}
		DrawRectangleRounded((Rectangle) { 144, 800 - 104 - 115, 512, 115 }, 57.5, 25, (Color) { 255 - 255 * c * (2 - c), 255 - 255 * c * (2 - c), 255 - 255 * c * (2 - c), 255 });
		DrawTextEx(Ar, "Restart", (Vector2) { 144 + 110, 800 - 104 - 115 + 10 }, 90, 1, (Color) { 255 * c * (2 - c), 255 * c * (2 - c), 255 * c * (2 - c), 255 });

		DrawRectangleRoundedLinesEx((Rectangle) { 144 + 5, 800 - 104 - 115 + 5, 512 - 10, 115 - 10 }, 57.5, 25, 5, (Color) { 0, 0, 0, 255 - 255 * c * (2 - c) });




		EndDrawing();



	}

	//EndDrawing(); 









//break;
//----------------------------------------------------------------------------------

// De-Initialization
//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
