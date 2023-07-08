#ifndef NOTES_H
#define NOTES_H

#include "headers.h"
#include "commun.h"
#include "minuterie.h"

void playNote(uint8_t note);
void playNote(uint8_t note, uint16_t duree_ms, uint8_t nRepetition);
void stopNote();

#endif // NOTES_H