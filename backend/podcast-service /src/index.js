const { podcastService } = require("./service");

exports.handler = async (event, _context) => {
  console.log("Received event", JSON.stringify(event, 3));

  switch (event.field) {
    case "getPodcast":
      const { id, next } = event.arguments.input;
      const podcast = await podcastService.getPodcast({ id, next });
      return podcast;

    case "getSearchResults":
      const { query } = event.arguments;
      const searchResults = await podcastService.getSearchResults(query);
      return searchResults;

    default:
      return "Unknown field, unable to resolve" + event.field, null;
  }
};
