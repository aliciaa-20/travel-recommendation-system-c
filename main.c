#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char text[500];
    struct node *left;
    struct node *right;
} node;

node* makeNode(const char* str) {
    node* temp = (node*)malloc(sizeof(node));
    if (!temp) {
        printf("Memory error!\n");
        exit(1);
    }
    snprintf(temp->text, sizeof(temp->text), "%s", str);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void ask(node* root) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        printf("\n====================================\n");
        printf("%s\n", root->text);
        printf("====================================\n");
        return;
    }

    int choice;
    printf("\n------------------------------------\n");
    printf("%s", root->text);
    printf("\nEnter choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1) ask(root->left);
    else if (choice == 2) ask(root->right);
    else printf("Invalid choice!\n");
}

int main() {
    node* climate = makeNode("Choose Climate:\n1. Hot/Tropical\n2. Cool/Temperate");

    node* hot_group = makeNode("Who are you traveling with?\n1. Solo/Family\n2. Friends/Work");
    node* cool_group = makeNode("Who are you traveling with?\n1. Solo/Family\n2. Friends/Work");

    climate->left = hot_group;
    climate->right = cool_group;

    node* hot_solo_or_family = makeNode("Choose:\n1. Solo\n2. Family");
    node* hot_friends_or_work = makeNode("Choose:\n1. Friends\n2. Work");
    hot_group->left = hot_solo_or_family;
    hot_group->right = hot_friends_or_work;

    node* cool_solo_or_family = makeNode("Choose:\n1. Solo\n2. Family");
    node* cool_friends_or_work = makeNode("Choose:\n1. Friends\n2. Work");
    cool_group->left = cool_solo_or_family;
    cool_group->right = cool_friends_or_work;

    // Hot + Solo
    node* hot_solo = makeNode("Do you prefer:\n1. Adventure/Activities\n2. Relaxation?");
    hot_solo_or_family->left = hot_solo;

    node* hot_solo_adventure = makeNode("Do you want:\n1. Water Activities\n2. Land Activities?");
    hot_solo->left = hot_solo_adventure;
    hot_solo_adventure->left = makeNode("Recommended: Bali, Thailand (Diving/Surfing)");
    hot_solo_adventure->right = makeNode("Recommended: Costa Rica, Peru (Hiking/Trekking)");

    node* hot_solo_relax = makeNode("Do you want:\n1. Beach\n2. Island Resort?");
    hot_solo->right = hot_solo_relax;
    hot_solo_relax->left = makeNode("Recommended: Maldives, Goa (Beach Relaxation)");
    hot_solo_relax->right = makeNode("Recommended: Santorini, Fiji (Island Resorts)");

    // Hot + Family
    node* hot_family = makeNode("Do you prefer:\n1. Theme Parks/Entertainment\n2. Nature/Scenic?");
    hot_solo_or_family->right = hot_family;

    node* hot_family_parks = makeNode("Choose:\n1. Disney/Universal\n2. Other Parks");
    hot_family->left = hot_family_parks;
    hot_family_parks->left = makeNode("Recommended: Orlando Disney, Tokyo Disneyland");
    hot_family_parks->right = makeNode("Recommended: Singapore Universal, Hong Kong Ocean Park");

    node* hot_family_nature = makeNode("Do you prefer:\n1. Beach Destinations\n2. Mountain/Forest?");
    hot_family->right = hot_family_nature;
    hot_family_nature->left = makeNode("Recommended: Kerala, Hawaii (Beaches)");
    hot_family_nature->right = makeNode("Recommended: Bali Highlands, Sri Lanka (Mountains)");

    // Hot + Friends
    node* hot_friends = makeNode("Do you prefer:\n1. Party Vibes\n2. Adventure/Exploration?");
    hot_friends_or_work->left = hot_friends;

    node* hot_friends_party = makeNode("Do you prefer:\n1. Beach Party\n2. City Nightlife?");
    hot_friends->left = hot_friends_party;
    hot_friends_party->left = makeNode("Recommended: Ibiza, Phuket (Beach Parties)");
    hot_friends_party->right = makeNode("Recommended: Bangkok, Miami (City Nightlife)");

    node* hot_friends_adv = makeNode("Do you want:\n1. Trekking/Outdoor\n2. Water Sports?");
    hot_friends->right = hot_friends_adv;
    hot_friends_adv->left = makeNode("Recommended: Thailand Trekking, Costa Rica Rainforest");
    hot_friends_adv->right = makeNode("Recommended: Philippines Surfing, Bali Diving");

    // Hot + Work
    node* hot_work = makeNode("Do you want:\n1. Urban City Experience\n2. Quiet Resort for Workation?");
    hot_friends_or_work->right = hot_work;

    node* hot_work_urban = makeNode("Choose:\n1. Modern Business Cities\n2. Historic Cities?");
    hot_work->left = hot_work_urban;
    hot_work_urban->left = makeNode("Recommended: Singapore, Dubai (Modern)");
    hot_work_urban->right = makeNode("Recommended: Miami, Istanbul (Historic)");

    node* hot_work_resort = makeNode("Choose:\n1. Beach Resort\n2. Island Retreat?");
    hot_work->right = hot_work_resort;
    hot_work_resort->left = makeNode("Recommended: Bali, Mauritius (Beach Resorts)");
    hot_work_resort->right = makeNode("Recommended: Maldives, Seychelles (Island Retreat)");

    // Cool + Solo
    node* cool_solo = makeNode("Do you prefer:\n1. Adventure (Mountains/Waterfalls)\n2. Relaxation (Lakes/Resorts)?");
    cool_solo_or_family->left = cool_solo;

    node* cool_solo_adv = makeNode("Do you want:\n1. Mountains\n2. Waterfalls?");
    cool_solo->left = cool_solo_adv;
    cool_solo_adv->left = makeNode("Recommended: Swiss Alps, Nepal Himalayas (Mountains)");
    cool_solo_adv->right = makeNode("Recommended: Iceland, Norway (Waterfalls)");

    node* cool_solo_relax = makeNode("Do you want:\n1. Lakes/Scenic Views\n2. Spa Resorts?");
    cool_solo->right = cool_solo_relax;
    cool_solo_relax->left = makeNode("Recommended: Canada Rockies, Norway Fjords (Scenic)");
    cool_solo_relax->right = makeNode("Recommended: New Zealand, Austria (Spa Resorts)");

    // Cool + Family
    node* cool_family = makeNode("Do you prefer:\n1. Theme Parks\n2. Nature/Scenic?");
    cool_solo_or_family->right = cool_family;

    node* cool_family_parks = makeNode("Choose:\n1. Disneyland\n2. Other Parks?");
    cool_family->left = cool_family_parks;
    cool_family_parks->left = makeNode("Recommended: Paris Disneyland, Tokyo Disneyland");
    cool_family_parks->right = makeNode("Recommended: Legoland Denmark, Europa Park Germany");

    node* cool_family_nature = makeNode("Do you want:\n1. Mountains\n2. Countryside?");
    cool_family->right = cool_family_nature;
    cool_family_nature->left = makeNode("Recommended: Switzerland Alps, Austria (Mountains)");
    cool_family_nature->right = makeNode("Recommended: Scotland, Ireland (Countryside)");

    // Cool + Friends
    node* cool_friends = makeNode("Do you prefer:\n1. Party (Festivals/Nightlife)\n2. Adventure (Snow Activities)?");
    cool_friends_or_work->left = cool_friends;

    node* cool_friends_party = makeNode("Do you want:\n1. Summer Festivals\n2. Nightlife?");
    cool_friends->left = cool_friends_party;
    cool_friends_party->left = makeNode("Recommended: Tomorrowland Belgium, Glastonbury UK");
    cool_friends_party->right = makeNode("Recommended: Berlin, Amsterdam (Nightlife)");

    node* cool_friends_adv = makeNode("Do you want:\n1. Mountains\n2. Snow Sports?");
    cool_friends->right = cool_friends_adv;
    cool_friends_adv->left = makeNode("Recommended: Nepal, Patagonia (Mountains)");
    cool_friends_adv->right = makeNode("Recommended: Canadian Rockies, Swiss Alps (Snow Sports)");

    // Cool + Work
    node* cool_work = makeNode("Do you want:\n1. Urban City Experience\n2. Quiet Resort for Workation?");
    cool_friends_or_work->right = cool_work;

    node* cool_work_urban = makeNode("Choose:\n1. Major Cities\n2. Smaller Cities?");
    cool_work->left = cool_work_urban;
    cool_work_urban->left = makeNode("Recommended: London, New York, Tokyo (Major)");
    cool_work_urban->right = makeNode("Recommended: Vienna, Geneva (Smaller)");

    node* cool_work_resort = makeNode("Choose:\n1. Mountain Resorts\n2. Countryside Retreat?");
    cool_work->right = cool_work_resort;
    cool_work_resort->left = makeNode("Recommended: Swiss Alps, Banff Canada (Mountain Resorts)");
    cool_work_resort->right = makeNode("Recommended: Iceland, Finland (Countryside Retreat)");

    printf("====================================\n");
    printf("Travel Recommendation System\n");
    printf("====================================\n");
    ask(climate);

    return 0;
}

