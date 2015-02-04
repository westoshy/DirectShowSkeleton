#include <iostream>
#include <dshow.h>
//#pragma include_alias( "dxtrans.h", "qedit.h" )
//#define __IDxtCompositor_INTERFACE_DEFINED__
//#define __IDxtAlphaSetter_INTERFACE_DEFINED__
//#define __IDxtJpeg_INTERFACE_DEFINED__
//#define __IDxtKey_INTERFACE_DEFINED__
#include <qedit.h>

#pragma comment(lib, "strmiids.lib")

int main(void)
{
  CoInitialize(NULL);

  // Filter Graph
  IGraphBuilder *pGraph = NULL;
  CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
    IID_IGraphBuilder, (void**)&pGraph);

  IMediaControl *pMediaControl;
  IMediaEvent *pEvent;

  pGraph->QueryInterface(IID_IMediaControl, (void**)&pMediaControl);
  pGraph->QueryInterface(IID_IMediaEvent, (void**)&pEvent);

  // create graph
  pGraph->RenderFile(L"sample.mp4", NULL);

  // run graph
  pMediaControl->Run();

  // wait finish
  long evCode;
  pEvent->WaitForCompletion(INFINITE, &evCode);

  // clean up
  pMediaControl->Release();
  pEvent->Release();
  pGraph->Release();
  CoUninitialize();

  return 0;
}