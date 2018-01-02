#ifndef __JB_LIST_BOX__
#define __JB_LIST_BOX__
///////////////////////////////////////////////////////////////////////////////
//
// File           : $Workfile:   JBListBox.hpp  $
// Version        : $Revision:   1.1  $
// Function       : An extended CListBox which can have default processing for
//                  double clicks on list box items and buttons with different 
//                  processing requirements associated with it.
//
// Author         : $Author:   Len  $
// Date           : $Date:   May 18 1998 07:40:36  $
//
// Notes          : Originally generated by ClassWizard.
// 
// Modifications  :
//
// $Log:   D:/Documents/JetByte/Source/JetByteTools/MFCTools/PVCS/JBListBox.hpv  $
// 
//    Rev 1.1   May 18 1998 07:40:36   Len
// Changes in message map functions due to using ON_CONTROL_REFLET_EX
// 
//    Rev 1.0   Dec 29 1997 11:15:14   Len
// Initial revision.
// 
///////////////////////////////////////////////////////////////////////////////
//
// Copyright 1997 JetByte Limited.
//
// JetByte Limited grants you ("Licensee") a non-exclusive, royalty free, 
// licence to use, modify and redistribute this software in source and binary 
// code form, provided that i) this copyright notice and licence appear on all 
// copies of the software; and ii) Licensee does not utilize the software in a 
// manner which is disparaging to JetByte Limited.
//
// This software is provided "AS IS," without a warranty of any kind. ALL
// EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES, INCLUDING 
// ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
// OR NON-INFRINGEMENT, ARE HEREBY EXCLUDED. JETBYTE LIMITED AND ITS LICENSORS 
// SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF 
// USING, MODIFYING OR DISTRIBUTING THE SOFTWARE OR ITS DERIVATIVES. IN NO 
// EVENT WILL JETBYTE LIMITED BE LIABLE FOR ANY LOST REVENUE, PROFIT OR DATA, 
// OR FOR DIRECT, INDIRECT, SPECIAL, CONSEQUENTIAL, INCIDENTAL OR PUNITIVE 
// DAMAGES, HOWEVER CAUSED AND REGARDLESS OF THE THEORY OF LIABILITY, ARISING 
// OUT OF THE USE OF OR INABILITY TO USE SOFTWARE, EVEN IF JETBYTE LIMITED 
// HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
//
// This software is not designed or intended for use in on-line control of
// aircraft, air traffic, aircraft navigation or aircraft communications; or in
// the design, construction, operation or maintenance of any nuclear
// facility. Licensee represents and warrants that it will not use or
// redistribute the Software for such purposes.
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Namespace: JetByteTools
///////////////////////////////////////////////////////////////////////////////

namespace JetByteTools {

///////////////////////////////////////////////////////////////////////////////
// Classes defined in this file
///////////////////////////////////////////////////////////////////////////////

class CJBListBox;             // A slightly smarter than normal CListBox.

///////////////////////////////////////////////////////////////////////////////
// CJBListBox 
///////////////////////////////////////////////////////////////////////////////

class CJBListBox : public CListBox
{
   public:

      // Exceptions we can throw.

      class ENoMemory {};

      // Classes we collaborate with...

      class ItemProcessor;    // Abstract class to process list items
      
      class ButtonList;

      // Enum used to determine what action should be taken after an
      // item is processed by a list processor.

      enum PostProcessAction_e 
      { 
         NoAction          = 0x00,      
         Delete            = 0x01,
         Unselect          = 0x02,     // Unselect can be combined with
         MoveUp            = 0x04,     // MoveUp and MoveDown...
         MoveUpUnselect    = 0x06,     // Use the convenience enums or | 
         MoveDown          = 0x08,     // together
         MoveDownUnselect  = 0x0A
      };

      // Enum used to determine when to activate an associated button 
      
      enum SelectionType_e 
      { 
         NoSelection     = 0x00,
         SingleSelection = 0x01,
         MultiSelection  = 0x02,
         AnySelection    = 0x03,
         NotTop          = 0x04,    // NotTop or NotBottom can be 
         NotBottom       = 0x08     // combined with Single, Multi or Any
      };

      // Template for simple item processors (ones that just return an action)

      template <CJBListBox::PostProcessAction_e simpleAction>
      class SimpleItemProcessor;

      // Use like this:
      // CJBListBox::SimpleItemProcessor<CJBListBox::MoveDown> downProcessor;
      // To create a processor that moves an item down...

      // Overrides
	   // ClassWizard generated virtual function overrides
	   //{{AFX_VIRTUAL(CJBListBox)
	   //}}AFX_VIRTUAL

      // Construction and destruction

      CJBListBox();

      ~CJBListBox();

      // List box manipulation

      int SelectItem(const int nIndex);

	   int CancelSelection(const int nIndex = -1);
      
	   int AddItem(const CString &theString, void *pData = NULL);

      int InsertItem(
         const int nIndex, 
         const CString &theString, 
         void *pData = NULL);

      int RemoveItem(const UINT nIndex);

      int MoveItemUp(const UINT nIndex, 
         const bool bSelectAfterMove = false);

      int MoveItemDown(const UINT nIndex, 
         const bool bSelectAfterMove = false);

      ItemProcessor *SetDefaultProcessor(ItemProcessor *pProcessor);

	   void ProcessSelectedItems(ItemProcessor *pProcessor = NULL);

      int GetSelectionCount();

      int GetSelectedItems(const int nMaxItems, LPINT rgIndex);

      // Button association

	   void AssociateButton(
		   CButton &theButton,                       // The button
         SelectionType_e selection = AnySelection, // Any selection enables
		   int nItems = 1);                          // No. items in box to enable

	   void AssociateButton(
		   UINT nButtonID,                           // ID of button
         ItemProcessor *pProcess = NULL,           // What happens when clicked
         SelectionType_e selection = AnySelection, // Any selection enables 
		   int nItems = 1);                          // No. items in box to enable

   protected:
   	// Generated message map functions
      //{{AFX_MSG(CJBListBox)
	   afx_msg BOOL OnDblclk();
	   afx_msg BOOL OnSelchange();
	   //}}AFX_MSG

	   DECLARE_MESSAGE_MAP()

   private:

      // Helper functions

      void SetButtonState();

      int MoveItem(
         const UINT nIndex, 
         const int nOffset,
         const bool bSelectAfterMove);
      
      void TopOrBottomSelected(
         bool &bTopSelected, 
         bool &bBottomSelected);

	   void ProcessSelectedItem(
         ItemProcessor *pProcess, 
         const int nIndex,
         PostProcessAction_e &action);

	   ButtonList *m_pButtonList;             // A list of associated buttons

	   ItemProcessor *m_pDefaultProcessor;    // How to process a double click

      // Prevent copying
         
      CJBListBox(const CJBListBox &rhs);              // Do not implement
      CJBListBox &operator=(const CJBListBox &rhs);   // Do not implement
};

///////////////////////////////////////////////////////////////////////////////
// CJBListBox::ItemProcessor
///////////////////////////////////////////////////////////////////////////////

class CJBListBox::ItemProcessor
{
	public :

      // Destruction...

		virtual ~ItemProcessor() { } 

      // Process an item

      virtual void ProcessSelectedItem(
         const int nIndex,                      // The item's index in the box
         const CString &theString,              // The string
         void *pData,                           // Item data
         PostProcessAction_e &action) = 0;      // What to do with the item
};

///////////////////////////////////////////////////////////////////////////////
// Standard item processor template
///////////////////////////////////////////////////////////////////////////////

template <CJBListBox::PostProcessAction_e theAction>
class CJBListBox::SimpleItemProcessor : public CJBListBox::ItemProcessor
{
   public :

      virtual void ProcessSelectedItem(
         const int,                      
         const CString &,              
         void *,                           
         CJBListBox::PostProcessAction_e &action)
      {
         action = theAction;
      }
};

///////////////////////////////////////////////////////////////////////////////
// Namespace: JetByteTools
///////////////////////////////////////////////////////////////////////////////

} // End of namespace JetByteTools 

#endif // __JB_LIST_BOX__

///////////////////////////////////////////////////////////////////////////////
// End of file
///////////////////////////////////////////////////////////////////////////////

