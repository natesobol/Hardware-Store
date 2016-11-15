
// Hardware StoreView.cpp : implementation of the CHardwareStoreView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Hardware Store.h"
#endif

#include "Hardware StoreDoc.h"
#include "Hardware StoreView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHardwareStoreView

IMPLEMENT_DYNCREATE(CHardwareStoreView, CView)

BEGIN_MESSAGE_MAP(CHardwareStoreView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CHardwareStoreView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CHardwareStoreView construction/destruction

CHardwareStoreView::CHardwareStoreView()
{
	// TODO: add construction code here

}

CHardwareStoreView::~CHardwareStoreView()
{
}

BOOL CHardwareStoreView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CHardwareStoreView drawing

void CHardwareStoreView::OnDraw(CDC* /*pDC*/)
{
	CHardwareStoreDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CHardwareStoreView printing


void CHardwareStoreView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CHardwareStoreView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CHardwareStoreView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CHardwareStoreView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CHardwareStoreView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CHardwareStoreView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CHardwareStoreView diagnostics

#ifdef _DEBUG
void CHardwareStoreView::AssertValid() const
{
	CView::AssertValid();
}

void CHardwareStoreView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHardwareStoreDoc* CHardwareStoreView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHardwareStoreDoc)));
	return (CHardwareStoreDoc*)m_pDocument;
}
#endif //_DEBUG


// CHardwareStoreView message handlers
