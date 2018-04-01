/* 
 *  
 *  
 * 
 * 

파일 상단에 
Easyrobot MainProcess;

void loop() {
  MainProcess.Update();
}

객체를 만드는법
  1. 구조체를 선언하듯이 class 선언
    class 원하는이름 : public EasyObject
    {
        public:
          // 이부분에 변수 선언
          int state = 0;
          // 처음 한번만 실행되는 함수
          void Start()
          {
          
          }
          // 0.001초에 한번 실행되는 함수
          void Update()
          {
            // update_delay = 1000; // 이 변수를 선언하면 Update()함수가 끝난후 1000 밀리세컨드 이후 다시 호출됨.
            // MainProcess.Delete(this); // 이 함수를 호출하면 이 객체는 더이상 작동하지 않음
          }
          // 삭제될때 한번 호출되는 함수
          void Close()
          {
            
          }
    };

  2. 메인프로세스 클래스에 방금 만든 객체 연결 (그러면 그 즉시 Start() 함수가 실행되며 0.001초에 한번씩 Update() 함수가 호출됨)
    MainProcess.Add(new 만든클래스이름());

*/








#ifndef EASYROBOT
#define EASYROBOT
#include <Arduino.h>
class EasyObject
{
  public:
  EasyObject* next = 0; // Next Object Address
  int update_delay = 0;
  virtual void Start() {} 
  virtual void Update() {}
  virtual void Close() {}
};
// Linked List
class List
{
  public:
  EasyObject* start; // Top Address
  List()
  {
    start = 0;
  }
  // this function is to link new object to top pointer
  Add(EasyObject* data)
  {
    // if list is null
    if (start == 0)
    {
      start = data;
    }
    else
    {
      // data -> start -> start.next ...
      data->next = start;
      start = data;
    }
  }
  // this function is to delete object in list
  Delete(EasyObject* data)
  {
    EasyObject* cstart = 0;
    EasyObject* nstart = start; // current pointer
    while(nstart != 0)
    {
      if (data == nstart)
      {
         if (cstart != 0) 
          {
            cstart->next = nstart->next;
          }
          else
          {
            start = nstart->next;
          }
          delete(data);
          break;
      }
      else
      {
        cstart = nstart;
        nstart = nstart->next;
      }
    }
  }
};


class Easyrobot
{
  List *box;    
  unsigned long lastUpdate;
  public:
  Easyrobot()
  {
    box = new List();
    lastUpdate = millis();
  }

  void Add(EasyObject* data)
  {
    data->Start();
    box->Add(data);
  }
  void Delete(EasyObject* data)
  {
    data->Close();
    box->Delete(data);
  }
  void Update()
  {
    if ((millis() - lastUpdate) >= 10) 
    {
      lastUpdate += 10;
      EasyObject* start = box->start;
      while (start != 0)
      {
        if ((start->update_delay) > 0) start->update_delay--;
        else start->Update();
        start = start->next;
      }
    }
  }
};
#endif
