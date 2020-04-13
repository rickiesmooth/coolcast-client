const axios = require("axios");

// Set config defaults when creating the instance
const instance = axios.create({
  baseURL: "https://listen-api.listennotes.com",
  headers: {
    "X-ListenAPI-Key": process.env.LISTEN_API_KEY
  }
});

exports.fetchSearchResults = async q =>
  await instance
    .get("/api/v2/typeahead", { params: { q, show_podcasts: 1 } })
    .catch(e => ({ errors: e.message }));

exports.fetchPodcast = async ({ id, next }) =>
  await instance
    .get(`/api/v2/podcasts/${id}`, { params: { next_episode_pub_date: next } })
    .catch(e => ({ errors: e.message }));
