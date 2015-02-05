#include <stdio.h>
#include <dshow.h>

#pragma comment(lib, "strmiids.lib")

#define	FILENAME L"sample.avih"

int main()
{
  IGraphBuilder *pGraphBuilder;
  IMediaControl *pMediaControl;

  // COM��������
  CoInitialize(NULL);

  // FilterGraph�𐶐�
  CoCreateInstance(CLSID_FilterGraph,
    NULL,
    CLSCTX_INPROC,
    IID_IGraphBuilder,
    (LPVOID *)&pGraphBuilder);

  // MediaControl�C���^�[�t�F�[�X�擾
  pGraphBuilder->QueryInterface(IID_IMediaControl,
    (LPVOID *)&pMediaControl);

  // Graph�𐶐�
  pMediaControl->RenderFile(FILENAME);

  // �Đ��J�n
  pMediaControl->Run();

  // �Đ����Ƀv���O�������I����Ă��܂�Ȃ��悤��
  MessageBox(NULL,
    L"Block Execution",
    L"Block",
    MB_OK);

  // ���������
  pMediaControl->Release();
  pGraphBuilder->Release();

  // COM�I��
  CoUninitialize();

  return 0;
}