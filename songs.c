#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"

// Frees list and returns null
struct song_node* free_list(struct song_node* s)
{
    struct song_node* temp;
    while (s)
    {
        temp = s->next;
        free(s);
        s = temp;
    }
    return temp;
}

// Creates node
struct song_node* create_node(char* t, char* a)
{
    struct song_node* s = malloc(sizeof(struct song_node));
    strcpy(s->title, t);
    strcpy(s->artist, a);
    s->next = NULL;
    return s;
}

// Prints individual song_node
void print_song(struct song_node* s)
{
    printf("Artist: %s\tTitle: %s\n", s->artist, s->title);
}

// Prints entire list
void print_list(struct song_node* s)
{
    while (s)
    {
        print_song(s);
        s = s->next;
    }
}

// Inserts node at front of linked list
struct song_node* insert_front(struct song_node* s, char* t, char* a)
{
    struct song_node* new_song = create_node(t, a);
    new_song->next = s;
    return new_song;
}

// Compares two songs by artist then title
int song_cmp(struct song_node* a, struct song_node* b)
{
    int artist_diff = strcmp(a->artist, b->artist);
    int title_diff = strcmp(a->title, b->title);
    if (artist_diff)
        return artist_diff;
    else
        return title_diff;
}

// Inserts nodes in alphabetical order (by artist then title, as per song_cmp)
struct song_node* insert_ordered(struct song_node* s, char* t, char* a)
{
    struct song_node* first = s;
    struct song_node* new_song = create_node(t, a);

    // if  linkedlist is empty or node is belongs in beginning (can be one-element)
    if (!s || song_cmp(new_song, s) <= 0)
    {
        s = insert_front(s, t, a);
        return s;
    }

    // for when linkedlist size >= 2
    while (s->next)
    {
        // if new_song is greater, go next
        if (song_cmp(new_song, s->next) > 0)
        {
            s = s->next;
        }
        else
        {
            // else set new_song to go next
            new_song->next = s->next;
            s->next = new_song;
            // return the first
            return first;
        }
    }

    // for  when node belongs at end of list (can be one element)
    // Two loops above also checks for one-element list, but only before
    if (song_cmp(new_song, s) > 0)
    {
        s->next = new_song;
    }
    else
    {
        s = insert_front(s, t, a);
        return s;
    }

    // return the first
    return first;
}

// Finds node given artist + song_node name
struct song_node* find_node_given_info(struct song_node* s, char* t, char* a)
{
    // while s is not NULL and neither title / artist matches, keeping looking next
    // when s is NULL or both title / artist match, return s
    while (s && (strcmp(s->title, t) || strcmp(s->artist, a)))
    {
        s = s->next;
    }
    return s;
}

// Finds first song_node of an artist given artist's name
struct song_node* find_artist_first(struct song_node* s, char* a)
{
    while (s && strcmp(s->artist, a))
    {
        s = s->next;
    }
    return s;
}

// Returns random node, but random needs to be initialized with srand(time(NULL)) first
struct song_node* random_node(struct song_node* front)
{
    int list_length = 0;
    struct song_node* rand_song = front;
    while (front)
    {
        front = front->next;
        list_length++;
    }
    int random_index = rand() % list_length;
    for (int i = 0; i < random_index; i++)
    {
        rand_song = rand_song->next;
    }
    return rand_song;
}

// Removes node and returns beginning of linked list
struct song_node* remove_node(struct song_node* front, char* t, char* a)
{
    struct song_node* temp;
    struct song_node* first = front;

    // if both title and artist match, move first to next
    if (strcmp(front->title, t) == 0 && strcmp(front->artist, a) == 0)
        first = front->next;
    
    // while front isn't NULL and at least one of title/artist doesn't match, 
    while (front != NULL && (strcmp(front->title, t) != 0 || strcmp(front->artist, a) != 0))
    {
        temp = front;
        front = front->next;
    }
    // if front isn't NULL, get rid of the node
    if (front != NULL)
    {
        temp->next = front->next;
        free(front);
    }
    return first;
}