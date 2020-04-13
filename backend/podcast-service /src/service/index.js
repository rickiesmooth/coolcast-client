const { fetchSearchResults, fetchPodcast } = require("./retrieve");
const { normalizeSearchResult } = require("./normalize");

class PodcastService {
  constructor(fetchSearchResults, fetchPodcast, normalizeSearchResults) {
    this.fetchSearchResults = fetchSearchResults;
    this.fetchPodcast = fetchPodcast;
    this.normalize = normalizeSearchResults;
  }
  getSearchResults(query) {
    return this.fetchSearchResults(query).then(this.normalize);
  }
  getPodcast(id) {
    return this.fetchPodcast(id).then(
      ({
        data: {
          id,
          episodes,
          title,
          thumbnail,
          description,
          next_episode_pub_date
        }
      }) => ({
        id,
        episodes,
        description,
        title,
        next: `${next_episode_pub_date}`,
        thumbnail
      })
    );
  }
}

exports.podcastService = new PodcastService(
  fetchSearchResults,
  fetchPodcast,
  normalizeSearchResult
);
