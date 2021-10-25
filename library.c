#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"
#include "library.h"

// creates the library
struct song_node** create_library(struct song_node** library)
{
    library = calloc(27, sizeof(struct song_node*));
    return library;
}

// adds a song_node to library
struct song_node** add_song_node(struct song_node** library, char* title, char* artist)
{
    int index = artistIndex(artist);
    library[index] = insert_ordered(library[index], title, artist);
    return library;
}

// finds a certain song_node in the library
struct song_node* find_song_in_library(struct song_node** library, char* title, char* artist)
{
    int index = artistIndex(artist);
    return find_node_given_info(library[index], title, artist);
}

// finds the first song_node of a certain artist in the library
struct song_node* find_artist_first_library(struct song_node** library, char* artist)
{
    int index = artistIndex(artist);
    return find_artist_first(library[index], artist);
}

void print_letter(struct song_node** library, char letter)
{
    struct song_node* temp = library[charIndex(letter)];
    printf("[\n");
    while (temp)
    {
        print_song(temp);
        temp = temp->next;
    }
    printf("]\n");
}

// prints out all the songs of a certain artist
void print_artist(struct song_node** library, char* artist)
{
    struct song_node* category = library[artistIndex(artist)];
    printf("%s: \n", artist);
    while (category)
    {
        if (!strcmp(category->artist, artist))
        {
            print_song(category);
        }
        category = category->next;
    }
    printf("\n");
}

// prints the contents of the entire library (letters that contain songs)
void print_library(struct song_node** library)
{
    int i;
    // if true, that means at least one of the 27 categories has been printed
    int printed = 0; 
    for (i = 0; i < 26; i++)
    {
        if (library[i])
        {
            printed = 1;
            // i + 97 is the character (from index to char)
            char l = i + 97;
            printf("%c: ", l);
            print_letter(library, l);
        }
    }
    if (library[26])
    {
        printed = 1;
        printf("Other: ");
        print_letter(library, '$'); // $ is used here because it will give index 27 when you run charIndex("$") in print_letter...
    }
    if (!printed)
    {
        // if none of the 27 categories has been printed, then you have an empty linked list
        printf("(empty)");
    }
}

// returns a series of randomly chosen songs (if you initialize random)
void shuffle_library(struct song_node** library, int num_songs)
{
    struct song_node* random_pick = 0;
    int i;
    for (i = 0; i < num_songs; i++)
    {
        while (!random_pick)
        {
            random_pick = library[rand() % 27];
        }
        print_song(random_node(random_pick));
        random_pick = 0;
    }
}

// deletes a song_node from the library
struct song_node** delete_song(struct song_node** library, char* title, char* artist)
{
    int index = artistIndex(artist);
    library[index] = remove_node(library[index], title, artist);
    return library;
}

// deletes the entire library
struct song_node** clear_library(struct song_node** library)
{
    int i;
    for (i = 0; i < 27; i++)
    {
        if (library[i]) 
        {
            library[i] = free_list(library[i]);
        }
    }
    return library;
}

// Returns the index of an artist (just the index of first char of their name)
int artistIndex(char* artist)
{
    return charIndex(artist[0]);
}

// Returns the index of a character, e.g. a is 0, b is 1, etc.
int charIndex(char c)
{
    if (isalpha(c))
    {
        return ((int)tolower(c)) - 97;
    }
    else
    {
        return 26;
    }
}
