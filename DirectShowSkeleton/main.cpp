#include <stdio.h>
#include <dshow.h>

#pragma comment(lib, "strmiids.lib")

#define	FILENAME L"sample.avih"

int main()
{
  IGraphBuilder *pGraphBuilder;
  IMediaControl *pMediaControl;

  // COMを初期化
  CoInitialize(NULL);

  // FilterGraphを生成
  CoCreateInstance(CLSID_FilterGraph,
    NULL,
    CLSCTX_INPROC,
    IID_IGraphBuilder,
    (LPVOID *)&pGraphBuilder);

  // MediaControlインターフェース取得
  pGraphBuilder->QueryInterface(IID_IMediaControl,
    (LPVOID *)&pMediaControl);

  // Graphを生成
  pMediaControl->RenderFile(FILENAME);

  // 再生開始
  pMediaControl->Run();

  // 再生中にプログラムが終わってしまわないように
  MessageBox(NULL,
    L"Block Execution",
    L"Block",
    MB_OK);

  // 資源を解放
  pMediaControl->Release();
  pGraphBuilder->Release();

  // COM終了
  CoUninitialize();

  return 0;
}