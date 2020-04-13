import React from "react";

import Podcast from "../components/Podcast.bs";
import Root from "../Root.bs";
const IndexPage = ({ id }) => (
  <Root>
    <Podcast id={id} />
  </Root>
);

export default IndexPage;
