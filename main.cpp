#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <bits/stdc++.h>
#include <time.h>
using namespace sf;
using namespace std;

int main()
{
      srand(time(0));
      int n=0,m=0,px=600,py=870,f=1,h=0,sn=0,yp=0,life=2,ran=1,tim1=-1,tim2=-1,tim3=-1,ps=1;

      RenderWindow window(VideoMode(1600, 900), "Arkanoid!");
      window.setFramerateLimit(60);

      Texture t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16;
      t1.loadFromFile("images/redy.png");
      t2.loadFromFile("images/card.png");
      t3.loadFromFile("images/ball.png");
      t4.loadFromFile("images/bat.png");
      t5.loadFromFile("images/bluey.png");
      t6.loadFromFile("images/greeny.png");
      t7.loadFromFile("images/white.png");
      t8.loadFromFile("images/arkan.png");
      t9.loadFromFile("images/life.png");
      t10.loadFromFile("images/sbat.png");
      t11.loadFromFile("images/lbat.png");
      t12.loadFromFile("images/S.png");
      t13.loadFromFile("images/B.png");
      t14.loadFromFile("images/D.png");
      t15.loadFromFile("images/fball.png");
      t16.loadFromFile("images/f1.png");


      Sprite sBackground(t2), sBall(t3), sPaddle(t4),menu(t8);
      Sprite getb(t13),gets(t12),getfi(t14),fu(t16);
      Sprite block[1000];
      Sprite lives[5];
      fu.setPosition(100,100);

      sPaddle.setPosition(px,py);
      getb.setPosition(-100,-100);
      gets.setPosition(-100,-100);
      getfi.setPosition(-100,-100);

      for (int j=0;j<=life;j++){
            lives[j].setTexture(t9);
            lives[j].setPosition(1500+ j*30,10);
      }

      /*for (int j=0;j<5;j++){
            dball[j].setTexture(t3);
      }*/


      //font and music
      //font and music
      sf::Font myFont;
      if (!myFont.loadFromFile("Font/FFF_Tusj.ttf")) {

      }

      sf::Music music;
      if (!music.openFromFile("music/yeah.ogg")) {

      }

      sf::Music musicc;
      if (!musicc.openFromFile("music/bop.ogg")) {

      }


      //level 1
      for (int i=1;i<=13;i++){
            for (int j=1;j<=8;j++){
                  block[n].setTexture(t1);
                  block[n].setPosition(215+ i*80,100+ j*30);
                  n++;
            }
      }
      m=n;

      double dx=9, dy=7,theta=0;
      double x=px+100, y=py-40;



      while (window.isOpen()){

            Event e;
            while (window.pollEvent(e)){
                  if (e.type == Event::Closed)
                  window.close();
            }

      //menu bar
      //menu bar
      //if(h==0){

      if(h==0){

            start:
            h=0;
            window.clear();

            window.draw(menu);
            sf::Text start;
            start.setFont( myFont );
            start.setString("START GAME");
            start.setFillColor(sf::Color::Red);
            start.setStyle(sf::Text::Regular);
            start.setCharacterSize(50);
            start.setPosition(500, 400);

            sf::Text exit;
            exit.setFont( myFont );
            exit.setString("EXIT");
            exit.setFillColor(sf::Color::Black);
            exit.setStyle(sf::Text::Regular);
            exit.setCharacterSize(50);
            exit.setPosition(500, 500);

            sf::Text sound;
            sound.setFont( myFont );
            sound.setString("SOUND   -press S");
            sound.setFillColor(sf::Color::Cyan);
            sound.setStyle(sf::Text::Regular);
            sound.setCharacterSize(25);
            sound.setPosition(600, 850);

            window.draw(start);
            window.draw(exit);
            window.draw(sound);
            window.display();


            if (Keyboard::isKeyPressed(Keyboard::Down)){
                  goto exit;
            }
            else if (Keyboard::isKeyPressed(Keyboard::S)){
                  goto sound;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Enter)){
                  h=22;
                  goto game;
            }
      }

      else if(h==1){

            exit:
            h=1;
            window.clear();
            window.draw(menu);

            sf::Text start;
            start.setFont( myFont );
            start.setString("START GAME");
            start.setFillColor(sf::Color::Black);
            start.setStyle(sf::Text::Regular);
            start.setCharacterSize(50);
            start.setPosition(500, 400);

            sf::Text exit;
            exit.setFont( myFont );
            exit.setString("EXIT");
            exit.setFillColor(sf::Color::Red);
            exit.setStyle(sf::Text::Regular);
            exit.setCharacterSize(50);
            exit.setPosition(500, 500);

            sf::Text sound;
            sound.setFont( myFont );
            sound.setString("SOUND   -press S");
            sound.setFillColor(sf::Color::Cyan);
            sound.setStyle(sf::Text::Regular);
            sound.setCharacterSize(25);
            sound.setPosition(600, 850);

            window.draw(start);
            window.draw(exit);
            window.draw(sound);
            window.display();

            if (Keyboard::isKeyPressed(Keyboard::Up)){
                  goto start;
            }
            else if (Keyboard::isKeyPressed(Keyboard::S)){
                  h=2;
                  goto sound;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Enter))return 0;
      }

      else if(h==2){

            sound:
            h=2;
            window.clear();

            if(sn==1 && yp==0){
                  music.play();
                  yp++;
            }

            window.draw(menu);

            sf::Text sound;
            sound.setFont( myFont );
            if(sn==1)sound.setString(" SOUND 'ON'\n\n SOUND OFF");
            else sound.setString(" SOUND ON\n\n SOUND 'OFF'");
            sound.setFillColor(sf::Color::Black);
            sound.setStyle(sf::Text::Regular);
            sound.setCharacterSize(40);
            sound.setPosition(500, 400);

            sf::Text esc;
            esc.setFont( myFont );
            esc.setString("press 'esc' to go back");
            esc.setFillColor(sf::Color::Blue);
            esc.setStyle(sf::Text::Regular);
            esc.setCharacterSize(25);
            esc.setPosition(500, 850);

            window.draw(sound);
            window.draw(esc);
            window.display();


            if (Keyboard::isKeyPressed(Keyboard::Down)){
                  sn=0;
                  yp=0;
                  goto sound;
            }

            else if (Keyboard::isKeyPressed(Keyboard::Up)){
                  sn=1;
                  //music.openFromFile("music/yeah.ogg");
                  goto sound;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Escape))goto start;
      }
      else if(h==3){
            pause:
            h=3;

            sf::Text resume;
            resume.setFont( myFont );
            if(ps==1)resume.setString("'Resume'");
            else resume.setString(" Resume ");
            resume.setFillColor(sf::Color::Black);
            resume.setStyle(sf::Text::Regular);
            resume.setCharacterSize(60);
            resume.setPosition(500, 350);

            sf::Text Exit;
            Exit.setFont( myFont );
            if(ps==1)Exit.setString(" Exit ");
            else Exit.setString("'Exit'");
            Exit.setFillColor(sf::Color::Black);
            Exit.setStyle(sf::Text::Regular);
            Exit.setCharacterSize(60);
            Exit.setPosition(500, 450);

            window.clear();

            window.draw(menu);
            window.draw(resume);
            window.draw(Exit);
            window.display();


            if(ps==1){
                  if (Keyboard::isKeyPressed(Keyboard::Enter)){
                        ps=1;
                        goto resume;
                  }
            }
            else{
                  if (Keyboard::isKeyPressed(Keyboard::Enter))return 0;
            }

            if (Keyboard::isKeyPressed(Keyboard::Down))ps=2;
            else if (Keyboard::isKeyPressed(Keyboard::Up))ps=1;

      }
      else{
      //game starts
      //game starts
      game:
      if(Keyboard::isKeyPressed(Keyboard::Escape))goto pause;
      resume:
      h=10;



      //ball hit bricks
      //ball hit bricks

      x+=dx;

      for(int i=0;i<n;i++){
            if (FloatRect(x+3,y+3,20,20).intersects(block[i].getGlobalBounds()) ){
                  if(sn==1){
                        if (!music.openFromFile("music/bop.ogg")) {
                        }
                        music.play();
                  }
                  else{
                        if (!music.openFromFile("music/null.ogg")) {
                        }
                        music.play();
                  }
                  block[i].setPosition(-500,-100);
                  if(tim3<0)dx=-dx;
                  m--;
                  ran=rand()%30;
                  if(ran==1 && tim1<=0){
                        getb.setPosition(x,y);
                        tim1=500;
                  }
                  else if(ran==4 && tim2<=0){
                        gets.setPosition(x,y);
                        tim2=500;
                  }
                  else if(ran==13 && tim3<=0){
                        getfi.setPosition(x,y);
                  }


            }
      }


      //ball hit bricks
      //ball hit bricks

      y+=dy;

      for (int i=0;i<n;i++){
            if ( FloatRect(x+3,y+3,20,20).intersects(block[i].getGlobalBounds()) ){
                  if(sn==1){
                        if (!music.openFromFile("music/bop.ogg")) {
                        }
                        music.play();
                  }
                  else{
                  }
                  block[i].setPosition(-500,-100);
                  if(tim3<0)dy=-dy;
                  m--;
                  ran=rand()%30;
                  if(ran==7 && tim1<=0){
                        getb.setPosition(x,y);
                        tim1=500;
                  }
                  else if(ran==4 && tim2<=0){
                        gets.setPosition(x,y);
                        tim2=500;
                  }
                  else if(ran==13 && tim3<=0){
                        getfi.setPosition(x,y);
                  }
            }
      }

      getb.move(0,5);
      gets.move(0,5);
      getfi.move(0,5);
      tim1--;
      tim2--;
      tim3--;
      if ((gets.getGlobalBounds()).intersects(sPaddle.getGlobalBounds()) ){
            //tim1=300;
            sPaddle=Sprite(t10);
            sPaddle.setPosition(px,py);

      }
      else if((getb.getGlobalBounds()).intersects(sPaddle.getGlobalBounds()) ){
            //tim2=300;
            sPaddle=Sprite(t11);
            sPaddle.setPosition(px,py);
      }
      else if((getfi.getGlobalBounds()).intersects(sPaddle.getGlobalBounds()) ){
            //tim3=300;
            sBall=Sprite(t15);
            tim3=300;
      }

      if(tim1<0 && tim2<0){
            sPaddle=Sprite(t4);
            sPaddle.setPosition(px,py);
      }
      if(tim3<0){
           sBall=Sprite(t3);
      }

      //ball hits boundary
      //ball hits boundary
      if (x<=0 || x>=1600)  dx=-dx;
      if (y<=0)  dy=-dy;
      if(y>=900){
            if(life>0){
                  life--;
                  px=600,py=870;
                  dx=9, dy=7;
                  x=px+100, y=py-40;
                  sPaddle.setPosition(px,py);
                  sBall.setPosition(x,y);

                  for(int i=0;i<=15;i++){
                  window.clear();
                  window.draw(sBackground);
                  window.draw(sBall);
                  window.draw(sPaddle);

                  for (int i=0;i<n;i++){
                        window.draw(block[i]);
                  }

                  for (int i=0;i<=life;i++){
                        window.draw(lives[i]);
                  }

                  window.display();
                  }
                  goto game;

            }
            else{
                  for(int i=0;i<30;i++){
                        window.clear();
                        sf::Text lose;
                        lose.setFont( myFont );
                        lose.setString("YOU LOSE");
                        lose.setFillColor(sf::Color::White);
                        lose.setStyle(sf::Text::Regular);
                        lose.setCharacterSize(80);
                        lose.setPosition(550, 400);
                        window.draw(sBackground);
                        window.draw(lose);
                        window.display();
                  }
            }

            return 0;
      }


      //bat movement
      //bat movement
      if (Keyboard::isKeyPressed(Keyboard::Right))
      {
            if(px<=1340){
                  sPaddle.move(25,0);
                  px+=25;
            }
      }
      if (Keyboard::isKeyPressed(Keyboard::Left))
      {
            if(px>=25){
                  sPaddle.move(-25,0);
                  px-=25;
            }
            else{
                  sPaddle.move(-px,0);
                  px=0;
            }
      }



      //ball hit bat
      //ball hit bat
      if(py-(y+25)<=0 && (x>=px && x<=px+250)){

                  dy=-dy;
                  if(sn==1){
                        if (!musicc.openFromFile("music/yeah.ogg")) {
                        }
                        musicc.play();
                  }
                  else{

                  }
      }

      //ball position
      //ball position
      sBall.setPosition(x,y);



      //level manually change
      //level manually change
      if(f==1){
            if (Keyboard::isKeyPressed(Keyboard::Num2)){
                  m=0;
                  goto lvl2 ;
            }
      }
      if(f==2){
            if (Keyboard::isKeyPressed(Keyboard::Num3)){
                  m=0;
                  goto lvl3;
            }
      }
      if(f==3){
            if (Keyboard::isKeyPressed(Keyboard::Num4)){
                  m=0;
                  goto lvl4;
            }
      }
      if(f==4){
            if (Keyboard::isKeyPressed(Keyboard::Num5)){
                  m=0;
                  goto lvl5;
            }
      }
      if(f==5){
            if (Keyboard::isKeyPressed(Keyboard::Num6)){
                  goto endd;
            }
      }



      window.clear();
      window.draw(sBackground);
      window.draw(sBall);
      window.draw(sPaddle);


      for (int i=0;i<n;i++){
            window.draw(block[i]);
      }

      for (int i=0;i<=life;i++){
            window.draw(lives[i]);
      }
      window.draw(gets);
      window.draw(getb);
      window.draw(getfi);
      window.display();


      //level upgrade+win
      //level upgrade+win
      if(m==0){


            if(f<=4){

            //level 5
            lvl5:
            if(f==4 && m==0){
                  f++;
                  for (int i=0;i<n;i++){
                        block[i].setPosition(-100,-100);
                  }
                  n=0, m=0;
                  for(int i=1; i<=7; i++){
                        for(int j=1; j<=i; j++){
                              if(i==7 || j==1 || j==i){
                                    block[n].setTexture(t7);
                                    block[n].setPosition(215+ i*80,310+ j*30);
                                    n++;
                              }
                        }
                  }
                  for(int i=1; i<=7; i++){
                        for(int j=i; j<=7; j++){
                              if(i==1 || j==7 || j==i){
                                    block[n].setTexture(t6);
                                    block[n].setPosition(775+ i*80,100+ j*30);
                                    n++;
                              }
                        }
                  }
                  for(int i=1; i<=7; i++){
                        for(int j=1; j<=i; j++){
                              if(i==7 || j==1 || j==i){
                                    block[n].setTexture(t5);
                                    block[n].setPosition(215+ i*80,340- j*30);
                                    n++;
                              }
                        }
                  }
                  for(int i=1; i<=7; i++){
                        for(int j=i; j<=7; j++){
                              if(i==1 || j==7 || j==i){
                                    block[n].setTexture(t1);
                                    block[n].setPosition(775+ i*80,550- j*30);
                                    n++;
                              }
                        }
                  }



                  m=n;
            }


            //level 4
            lvl4:
            if(f==3 && m==0){
                  f++;
                  for (int i=0;i<n;i++){
                        block[i].setPosition(-100,-100);
                  }
                  n=0, m=0;

                  for(int i=0;i<15;i++){
                        block[n].setTexture(t7);
                        block[n].setPosition(115+80+ i*80,210);
                        n++;
                  }
                  for(int i=1; i<=8; i++){
                        for(int j=1; j<=i; j++){
                              if(i==8 || /*j==1 ||*/ j<=i){
                                    block[n].setTexture(t7);
                                    block[n].setPosition(115+ i*80,210+ j*30);
                                    n++;
                              }
                        }
                  }
                  for(int i=1; i<=7; i++){
                        for(int j=i; j<=7; j++){
                              if(i==1 || j>=i){
                                    block[n].setTexture(t7);
                                    block[n].setPosition(755+ i*80,450- j*30);
                                    n++;
                              }
                        }
                  }
                  m=n;
            }


            //level 3
            lvl3:
            if(f==2 && m==0){
                  f++;
                  for (int i=0;i<n;i++){
                        block[i].setPosition(-100,-100);
                  }
                  n=0, m=0;
                  for(int i=1; i<=15; i++){
                        for(int j=1; j<=10; j++){
                              if(i%2!=0 || j==1 || j==10){
                                    block[n].setTexture(t6);
                                    block[n].setPosition(115+ i*80,100+ j*30);
                                    n++;
                              }

                        }
                  }

                  /*for(int i=1; i<=5; i++){
                        for(int j=1; j<=10; j++){
                              if(i==1 || i==5 || j==1 || j==10){
                                    block[n].setTexture(t6);
                                    block[n].setPosition(515+ i*80,100+ j*30);
                                    n++;
                              }
                        }
                  }*/

                  m=n;
            }


            //level 2
            lvl2:
            if(f==1 && m==0){
                  f++;
                  for (int i=0;i<n;i++){
                        block[i].setPosition(-100,-100);
                  }
                  n=0,m=0;

                  for(int i=1; i<=15; i++){
                        for(int j=1; j<=i; j++){
                              if(i==15 || j==1 || j==i){
                                    block[n].setTexture(t5);
                                    block[n].setPosition(115+ i*80,100+ j*30);
                                    n++;
                              }
                        }
                  }

                  m=n;
            }


            //level 1
            lvl1:
            if(f==0 && m==0){
                  f++;
                  for (int i=1;i<=13;i++){
                        for (int j=1;j<=8;j++){
                              block[n].setTexture(t1);
                              block[n].setPosition(215+ i*80,100+ j*30);
                              n++;
                        }
                  }
                  m=n;
            }


            for(int i=0;i<20;i++){
                  window.clear();
                  sf::Text lvl;
                  lvl.setFont( myFont );
                  lvl.setString("LEVEL PASSED");
                  lvl.setFillColor(sf::Color::White);
                  lvl.setStyle(sf::Text::Regular);
                  lvl.setCharacterSize(80);
                  lvl.setPosition(550, 400);
                  window.draw(sBackground);
                  window.draw(lvl);
                  window.display();
            }



            px=600,py=870;
            dx=9, dy=7;
            x=px+100, y=py-40;
            sPaddle.setPosition(px,py);
            sBall.setPosition(x,y);

            for(int i=0;i<=15;i++){
                  window.clear();
                  window.draw(sBackground);
                  window.draw(sBall);
                  window.draw(sPaddle);

                  for (int i=0;i<n;i++){
                        window.draw(block[i]);
                  }

                  for (int i=0;i<=life;i++){
                        window.draw(lives[i]);
                  }
                  /*window.draw(getb);
                  window.draw(gets);*/

                  window.display();
            }
            goto game;

            }
            else{
                  endd:
                  for(int i=0;i<30;i++){
                        window.clear();
                        sf::Text win;
                        win.setFont( myFont );
                        win.setString("YOU WIN");
                        win.setFillColor(sf::Color::White);
                        win.setStyle(sf::Text::Regular);
                        win.setCharacterSize(80);
                        win.setPosition(570, 400);
                        window.draw(sBackground);
                        window.draw(win);
                        window.display();
                  }
                  return 0;

            }
      }
      }

      }

      return 0;
}

