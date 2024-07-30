#include "okr.h"
#define PcdGet32(TokenName)  _PCD_GET_MODE_32_##TokenName
#define _PCD_GET_MODE_32_PcdMaximumUnicodeStringLength 1000000

/**
  [ATTENTION] This function will be deprecated for security reason.

  Copies up to a specified length from one Null-terminated Unicode string  to 
  another Null-terminated Unicode string and returns the new Unicode string.

  This function copies the contents of the Unicode string Source to the Unicode
  string Destination, and returns Destination. At most, Length Unicode
  characters are copied from Source to Destination. If Length is 0, then
  Destination is returned unmodified. If Length is greater that the number of
  Unicode characters in Source, then Destination is padded with Null Unicode
  characters. If Source and Destination overlap, then the results are
  undefined.

  If Length > 0 and Destination is NULL, then ASSERT().
  If Length > 0 and Destination is not aligned on a 16-bit boundary, then ASSERT().
  If Length > 0 and Source is NULL, then ASSERT().
  If Length > 0 and Source is not aligned on a 16-bit boundary, then ASSERT().
  If Source and Destination overlap, then ASSERT().
  If PcdMaximumUnicodeStringLength is not zero, and Length is greater than 
  PcdMaximumUnicodeStringLength, then ASSERT().
  If PcdMaximumUnicodeStringLength is not zero, and Source contains more than
  PcdMaximumUnicodeStringLength Unicode characters, not including the Null-terminator,
  then ASSERT().

  @param  Destination A pointer to a Null-terminated Unicode string.
  @param  Source      A pointer to a Null-terminated Unicode string.
  @param  Length      The maximum number of Unicode characters to copy.

  @return Destination.

**/
CHAR16 *
EFIAPI
StrnCpy (
  OUT     CHAR16                    *Destination,
  IN      CONST CHAR16              *Source,
  IN      UINTN                     Length
  )
{
  CHAR16                            *ReturnValue;

  if (Length == 0) {
    return Destination;
  }

  //
  // Destination cannot be NULL if Length is not zero
  //
  ASSERT (Destination != NULL);
  ASSERT (((UINTN) Destination & BIT0) == 0);

  //
  // Destination and source cannot overlap
  //
  ASSERT ((UINTN)(Destination - Source) > StrLen (Source));
  ASSERT ((UINTN)(Source - Destination) >= Length);

  if (PcdGet32 (PcdMaximumUnicodeStringLength) != 0) {
    ASSERT (Length <= PcdGet32 (PcdMaximumUnicodeStringLength));
  }

  ReturnValue = Destination;

  while ((*Source != L'\0') && (Length > 0)) {
    *(Destination++) = *(Source++);
    Length--;
  }

  ZeroMem (Destination, Length * sizeof (*Destination));
  return ReturnValue;
}