#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "songs.h"
#include "library.h"

void linked_list_test();
void library_test();

int main()
{
    srand(time(NULL));

    linked_list_test();
    printf("\n\n\n\n");
    printf("\n\n\n\n");
    library_test();

    return 0;
}

// Tests for the linked list part
void linked_list_test()
{
    printf("LINKED LIST TESTS\n");

    // insert_front tests
    printf("=========================================================================\n\n");
    printf("Testing insert_front:\n");
    struct song_node *songs = create_node("strawberry moon", "IU");
    songs = insert_front(songs, "Strawberry Moon", "TWICE");
    songs = insert_front(songs, "Into You", "Matisse & Sadko");
    songs = insert_front(songs, "Timber", "Pitbull");
    songs = insert_front(songs, "Vacation ", "Damon Empero");
    songs = insert_front(songs, "Memories", "Maroon 5");
    songs = insert_front(songs, "TIRED", "Jasmine Sokko");
    songs = insert_front(songs, "The Lazy Song", "Bruno Mars");
    songs = insert_front(songs, "If You Seek Amy", "Brittany Spears");
    songs = insert_front(songs, "Girl On Fire", "Alicia Keys");
    songs = insert_front(songs, "Shape of You", "Ed Sheeran");
    songs = insert_front(songs, "Raindrop", "IU");
    print_list(songs);
    printf("\n");

    // insert_ordered tests
    printf("=========================================================================\n\n");
    printf("Testing insert_ordered:\n");
    struct song_node *songs2 = 0;
    songs2 = insert_ordered(songs2, "Shape of You", "Ed Sheeran");
    songs2 = insert_ordered(songs2, "Apologize", "OneRepublic");
    songs2 = insert_ordered(songs2, "One Dance", "Drake");
    songs2 = insert_ordered(songs2, "See You Again", "Wiz Khalifa");
    songs2 = insert_ordered(songs2, "Way Back Home", "Shaun");
    songs2 = insert_ordered(songs2, "Sorry", "Justin Bieber");
    songs2 = insert_ordered(songs2, "Congratulations", "Post Malone");
    songs2 = insert_ordered(songs2, "Believer", "Imagine Dragons");
    songs2 = insert_ordered(songs2, "Mine", "Bazzi");

    print_list(songs2);
    printf("\n");

    // print_list tests
    printf("=========================================================================\n\n");
    printf("Testing print_list:\n");
    print_list(songs);
    printf("\n");

    // print_song tests
    printf("=========================================================================\n\n");
    printf("Testing print_song:\n");
    print_song(songs);
    printf("\n");

    // find_node_given_info tests
    printf("=========================================================================\n\n");
    printf("Testing find_node_given_info:\n");
    printf("looking for [Ed Sheeran: Shape of You]\n");
    struct song_node *search = find_node_given_info(songs, "Shape of You", "Ed Sheeran");
    if (search)
    {
        printf("node found! %s: %s\n", search->artist, search->title);
    }
    else
    {
        printf("node not found\n");
    }

    printf("\nlooking for [IU: Raindrop]\n");
    search = find_node_given_info(songs, "Raindrop", "IU");
    if (search)
    {
        printf("node found! %s: %s\n", search->artist, search->title);
    }
    else
    {
        printf("node not found\n");
    }
    printf("\n");

    // find_artist_first tests
    printf("=========================================================================\n\n");
    printf("Testing find_artist_first:\n");

    printf("looking for [IU]\n");
    search = find_artist_first(songs, "IU");
    if (search)
    {
        printf("artist found! ");
        print_list(search);
    }
    else
    {
        printf("artist not found\n");
    }

    printf("\nlooking for [TWICE]\n");
    search = find_artist_first(songs, "TWICE");
    if (search)
    {
        printf("artist found! ");
        print_list(search);
    }
    else
    {
        printf("artist not found\n");
    }

    printf("\nlooking for [Tokyo Machine]\n");
    search = find_artist_first(songs, "Tokyo Machine");
    if (search)
    {
        printf("artist found! ");
        print_list(search);
    }
    else
    {
        printf("artist not found\n");
    }
    printf("\n");

    // song_cmp tests
    printf("=========================================================================\n\n");
    printf("Testing songcmp:\n");

    printf("Comparing [IU: Raindrop] to [IU: Raindrop]\n");
    struct song_node *iu_raindrop = find_node_given_info(songs, "Raindrop", "IU");
    printf("%d\n", song_cmp(iu_raindrop, iu_raindrop));

    printf("Comparing [IU: Raindrop] to [Imagine Dragons: Believer]\n");
    struct song_node *id_believer = find_node_given_info(songs2, "Believer", "Imagine Dragons");
    printf("%d\n", song_cmp(iu_raindrop, id_believer));

    // random_node tests
    printf("=========================================================================\n\n");
    printf("Testing random_node:\n");
    printf("List of Songs:\n");
    print_list(songs);
    printf("\nRandom Songs:\n");
    print_song(random_node(songs));
    print_song(random_node(songs));
    print_song(random_node(songs));
    printf("\n");

    // remove_node tests
    printf("=========================================================================\n\n");
    printf("Testing remove_node:\n");

    printf("List of Songs:\n");
    print_list(songs);
    printf("\n");

    printf("Removing [Imagine Dragons, Believer");
    songs = remove_node(songs, "Believer", "Imagine Dragons");

    printf("List With Removed song_node:\n");
    print_list(songs);

    printf("\n");

    // free_list tests
    printf("=========================================================================\n\n");
    printf("Testing free_list:\n");

    songs = free_list(songs);

    printf("Freed list:\n");
    print_list(songs);

    printf("\n");
}

// Tests for the library
void library_test()
{
    printf("MUSIC LIBRARY TESTS\n");
    struct song_node **library = create_library();

    // artistIndex test
    printf("=========================================================================\n\n");
    printf("Testing artistIndex:\n");

    struct song_node *a_test = create_node("MONEY", "LISA");
    printf("%c: %d\n", (a_test->artist)[0], artistIndex(a_test->artist));

    struct song_node *b_test = create_node("LALISA", "LISA");
    printf("%c: %d\n", (b_test->artist)[0], artistIndex(b_test->artist));

    printf("\n");

    // add_song_node test
    printf("=========================================================================\n\n");
    printf("Testing add_song_node:\n");

    library = add_song_node(library, "Firework", "Katy Perry");
    library = add_song_node(library, "Whistle", "Flo Rida");
    library = add_song_node(library, "Back to You", "Louis Tomlinson");
    library = add_song_node(library, "Cold Wind Blows", "Eminem");
    library = add_song_node(library, "Dance with the Devil", "Immortal Technique");
    library = add_song_node(library, "Teleprompter", "Êmia");
    library = add_song_node(library, "heart in tokyo", "gasoline");
    library = add_song_node(library, "are you sure", "Loote");
    library = add_song_node(library, "Youngblood", "5 Seconds of Summer");

    print_library(library);

    // find_song_in_library test
    printf("=========================================================================\n\n");
    printf("Testing find_song_in_library:\n");

    printf("looking for [Katy Perry: Firework]\n");
    struct song_node *search = find_song_in_library(library, "Firework", "Katy Perry");
    if (search)
    {
        printf("node found! %s: %s\n", search->artist, search->title);
        printf("\n");
    }
    else
    {
        printf("node not found\n");
    }

    printf("looking for [Flo Rida: Whistle]\n");
    search = find_song_in_library(library, "Whistle", "Flo Rida");
    if (search)
    {
        printf("node found! %s: %s\n", search->artist, search->title);
        printf("\n");
    }
    else
    {
        printf("node not found\n");
    }
    printf("\n");

    printf("looking for [Axel Johansson: The River]\n");
    search = find_song_in_library(library, "The River", "Axel Johansson");
    if (search)
    {
        printf("node found! %s: %s\n", search->artist, search->title);
        printf("\n");
    }
    else
    {
        printf("node not found\n");
    }

    // find_artist_first_library test
    printf("=========================================================================\n\n");
    printf("Testing find_artist_first_library:\n");

    printf("looking for [Eminem]\n");
    search = find_artist_first_library(library, "Eminem");
    if (search)
    {
        printf("artist found! ");
        print_list(search);
        printf("\n");
    }
    else
    {
        printf("artist not found\n");
    }

    printf("looking for [wont be found]\n");
    search = find_artist_first_library(library, "wont be found");
    if (search)
    {
        printf("artist found! ");
        print_list(search);
        printf("\n");
    }
    else
    {
        printf("artist not found\n");
    }
    printf("\n");

    // print_letter test
    printf("=========================================================================\n\n");
    printf("Testing print_letter:\n");

    printf("Printing Letter l:\n");
    print_letter(library, 'l');

    printf("Printing Letter k:\n");
    print_letter(library, 'k');
    printf("\n");

    // delete_song test
    printf("=========================================================================\n\n");
    printf("Testing delete_song:\n");
    printf("library before deletion:\n");
    print_library(library);


    printf("\n\n\nRemoving [Katy Perry, Firework]:\n");
    library = delete_song(library, "Firework", "Katy Perry");
    printf("Removing [Flo Rida, Whistle]:\n");
    library = delete_song(library, "Whistle", "Flo Rida");
    printf("\n\n\nResult:");

    print_library(library);
    printf("\n");

    // clear_library test
    printf("=========================================================================\n\n");
    printf("Testing clear_library:\n");
    library = clear_library(library);
    print_library(library);
    printf("\n");

    // re-add songs to library
    printf("=========================================================================\n\n");
    printf("Adding songs to empty library:\n");

    library = add_song_node(library, "Hostage", "Jane & The Boy");
    library = add_song_node(library, "Bedroom", "Raquel Castro · The Wildcardz");
    library = add_song_node(library, "All the Way Up", "Hadar Sopher");
    library = add_song_node(library, "I Got Me", "Jane & The Boy");
    library = add_song_node(library, "Lose Myself", "Ryan Prewett");
    library = add_song_node(library, "Castaway", "Lightboys");
    library = add_song_node(library, "Love You Better", "Aaron Kellim");
    library = add_song_node(library, "Truth Is", "Ryan Prewett");
    library = add_song_node(library, "Wasted Time", "Nate Rose & Santino LaBoy & Sober");
    library = add_song_node(library, "Your Captain", "Banana Split");
    library = add_song_node(library, "Yours", "Sajan Nauriyal");
    library = add_song_node(library, "Alive", "Lux-Inspira");
    library = add_song_node(library, "Always Enough", "Sajan Nauriyal");
    library = add_song_node(library, "Don\'t Feel", "Ryan Prewett");
    library = add_song_node(library, "Don\'t Stand a Chance", "Ofrin");
    library = add_song_node(library, "Everything or Nothing", "Tux Bolo ");
    library = add_song_node(library, "Glow", "Sajan Nauriyal");
    library = add_song_node(library, "Good", "Above Envy ");
    library = add_song_node(library, "Kids", "Christopher Young");
    library = add_song_node(library, "Mindplay", "Roza");

    print_library(library);

    // print_artist test
    printf("=========================================================================\n\n");
    printf("Testing print_artist:\n");

    printf("Printing [Jane & The Boy]:\n");
    print_artist(library, "Jane & The Boy");

    printf("\nPrinting [Ryan Prewett]:\n");
    print_artist(library, "Ryan Prewett");

    printf("\nPrinting [Aaron Kellim]:\n");
    print_artist(library, "Aaron Kellim");

    printf("\n");

    // shuffle_library test
    printf("=========================================================================\n\n");
    printf("Testing shuffle_library:\n");
    printf("Printing 5 random songs:\n");
    shuffle_library(library, 5);
    printf("\n");
}
