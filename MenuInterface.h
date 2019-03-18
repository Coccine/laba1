#ifndef _MENU_INTERFACE_
#define _MENU_INTERFACE_

void DisplayMainMenu();
void DisplayOptionsMenu();
void DisplayFirstLabsTask();
void DisplayAboutInfo();

void SetOptions();
int getChoice();
bool askAboutSaving(int mode);

#endif