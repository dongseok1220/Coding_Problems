#include <string>
#include <vector>
#include <unordered_map>
#include <iostream> 
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    // Step 1: 장르별 총 재생 횟수 계산
    unordered_map<string, int> genre_play_count;
    for (int i = 0; i < genres.size(); i++) {
        genre_play_count[genres[i]] += plays[i];
    }

    // Step 2: 장르별로 노래 그룹화
    unordered_map<string, vector<pair<int, int>>> songs_by_genre;
    for (int i = 0; i < genres.size(); i++) {
        songs_by_genre[genres[i]].emplace_back(plays[i], i);
    }

    // Step 3: 장르별로 노래 정렬
    for (auto& [genre, songs] : songs_by_genre) {
        sort(songs.begin(), songs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        });
    }

    // Step 4: 베스트 앨범 구성
    vector<pair<int, string>> sorted_genres;
    for (const auto& [genre, play_count] : genre_play_count) {
        sorted_genres.emplace_back(play_count, genre);
    }
    sort(sorted_genres.begin(), sorted_genres.end(), greater<pair<int, string>>());

    vector<int> best_album;
    for (const auto& [play_count, genre] : sorted_genres) {
        const auto& songs = songs_by_genre[genre];
        for (int i = 0; i < songs.size() && i < 2; i++) {
            best_album.push_back(songs[i].second);
        }
    }

    return best_album;
}