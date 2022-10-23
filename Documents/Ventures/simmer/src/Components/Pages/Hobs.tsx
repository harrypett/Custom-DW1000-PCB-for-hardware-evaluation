import React from "react";
import styled from "styled-components";

const Hobs = () => {
  return (
    <>
      <p>Hobs</p>
      <div>
        <Hob />
      </div>
    </>
  );
};

export default Hobs;

const Hob = styled.div`
  color: red;
  display: block;
`;
