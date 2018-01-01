//***************************************************************************
//                          main.cpp  -  description
//                             -------------------
//  begin            : Mi Nov 8 11:58:45 2006
//  generated by     : pvdevelop (C) 2000-2006 by Lehrig Software Engineering
//  email            : lehrig@t-online.de
//***************************************************************************
#include "pvapp.h"
// todo: comment me out. you can insert these objects as extern in your masks.
//rlModbusClient     modbus(modbusdaemon_MAILBOX,modbusdaemon_SHARED_MEMORY,modbusdaemon_SHARED_MEMORY_SIZE);
//rlSiemensTCPClient siemensTCP(siemensdaemon_MAILBOX,siemensdaemon_SHARED_MEMORY,siemensdaemon_SHARED_MEMORY_SIZE);
//rlPPIClient        ppi(ppidaemon_MAILBOX,ppidaemon_SHARED_MEMORY,ppidaemon_SHARED_MEMORY_SIZE);

static int getParams(const char *ini, POPUP_DATA *popup)
{
  const char *cptr;

  cptr = strstr(ini, "popup=");
  if (cptr != NULL)
  {
    if (cptr[6] == 't') popup->popup = true;
    else                popup->popup = false;
  }

  cptr = strstr(ini, "x1=");
  if (cptr != NULL)
  {
    sscanf(cptr, "x1=%f", &popup->x1);
  }

  cptr = strstr(ini, "y1=");
  if (cptr != NULL)
  {
    sscanf(cptr, "y1=%f", &popup->y1);
  }

  cptr = strstr(ini, "x0=");
  if (cptr != NULL)
  {
    sscanf(cptr, "x0=%f", &popup->x0);
  }

  cptr = strstr(ini, "y0=");
  if (cptr != NULL)
  {
    sscanf(cptr, "y0=%f", &popup->y0);
  }

  cptr = strstr(ini, "scale=");
  if (cptr != NULL)
  {
    sscanf(cptr, "scale=%f", &popup->scale);
    printf("scale main:%f\n", popup->scale);
  }

  cptr = strstr(ini, "svgx0=");
  if (cptr != NULL)
  {
    sscanf(cptr, "svgx0=%f", &popup->svgx0);
  }

  cptr = strstr(ini, "svgy0=");
  if (cptr != NULL)
  {
    sscanf(cptr, "svgy0=%f", &popup->svgy0);
  }

  return 0;
}

int pvMain(PARAM *p)
{
int ret;

  POPUP_DATA popup_data;
  memset(&popup_data, 0, sizeof(popup_data));
  p->user = &popup_data;

  pvSetCaption(p,"pvsexample");
  pvResize(p,0,1280,1024);
  //pvScreenHint(p,1024,768); // this may be used to automatically set the zoomfactor
  ret = 1;
  pvGetInitialMask(p);
  if(strcmp(p->initial_mask,"mask1") == 0) 
  {
    ret = 1;
  }  
  else if(strncmp(p->initial_mask,"mask10",6) == 0)
  {
    getParams(p->initial_mask, &popup_data);
    ret = 10;
  }
  if(trace) printf("initial_mask=%s\n",p->initial_mask);
  if(trace) printf("url=%s\n",p->url);
  pvDownloadFile(p,"index.html"); // provide help for the user
                                  // you can also download pages linked within index.html
  pvDownloadFile(p,"page.html");  // provide help for the user
                                  // you can also download pages linked within index.html

  while(1)
  {
    switch(ret)
    {
      case 11:
        pvStatusMessage(p,-1,-1,-1,"mask11");
        ret = show_mask11(p);
        break;
      case 10:
        pvStatusMessage(p,-1,-1,-1,"mask10");
        ret = show_mask10(p);
        break;
      case 9:
        pvStatusMessage(p,-1,-1,-1,"mask9");
        ret = show_mask9(p);
        break;
      case 8:
        pvStatusMessage(p,-1,-1,-1,"mask8");
        ret = show_mask8(p);
        break;
      case 7:
        pvStatusMessage(p,-1,-1,-1,"mask7");
        ret = show_mask7(p);
        break;
      case 6:
        pvStatusMessage(p,-1,-1,-1,"mask6");
        ret = show_mask6(p);
        break;
      case 5:
        pvStatusMessage(p,-1,-1,-1,"mask5");
        ret = show_mask5(p);
        break;
      case 4:
        pvStatusMessage(p,-1,-1,-1,"mask4");
        ret = show_mask4(p);
        break;
      case 3:
        pvStatusMessage(p,-1,-1,-1,"mask3");
        ret = show_mask3(p);
        break;
      case 2:
        pvStatusMessage(p,-1,-1,-1,"mask2");
        ret = show_mask2(p);
        break;
      case 1:
        pvStatusMessage(p,-1,-1,-1,"mask1");
        ret = show_mask1(p);
        break;
      default:
        return 0;
    }
  }
}

#ifdef USE_INETD
int main(int ac, char **av)
{
PARAM p;

  pvInit(ac,av,&p);
  /* here you may interpret ac,av and set p->user to your data */
  pvMain(&p);
  return 0;
}
#else  // multi threaded server
int main(int ac, char **av)
{
PARAM p;
int   s;

  pvInit(ac,av,&p);
  /* here you may interpret ac,av and set p->user to your data */
  while(1)
  {
    s = pvAccept(&p);
    if(s != -1) pvCreateThread(&p,s);
  }
  return 0;
}
#endif
